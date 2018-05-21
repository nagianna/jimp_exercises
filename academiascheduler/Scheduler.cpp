//
// Created by Ania on 2018-05-17.
//



#include "Scheduler.h"

#include <cstddef>
#include <algorithm>

namespace academia {

    SchedulingItem::SchedulingItem() = default;

    SchedulingItem::SchedulingItem(int sch_course_id, int teacher_id, int sch_room_id, int time_slot, int sch_year) {
        course_id_=sch_course_id;
        teacher_id_=teacher_id;
        room_id_=sch_room_id;
        time_slot_=time_slot;
        year_=sch_year;
    }

    SchedulingItem::~SchedulingItem() {}

    int SchedulingItem::CourseId() const {
            return course_id_;
    }

    int SchedulingItem::TeacherId() const {
            return teacher_id_;
    }

    int SchedulingItem::RoomId() const {
            return room_id_;
    }

    int SchedulingItem::TimeSlot() const {
            return time_slot_;
    }

    int SchedulingItem::Year() const {
            return year_;
    }




    Schedule Schedule::OfTeacher(int teacher_id) const {
        Schedule of_teacher;
        std::copy_if(this->schedule_items_.begin(), this->schedule_items_.end(), std::back_inserter(of_teacher.schedule_items_), [teacher_id](SchedulingItem index){
            return (index.TeacherId()==teacher_id);
        });
        return of_teacher;
    }

    Schedule Schedule::OfRoom(int sch_room_id) const {
        Schedule of_room;
        std::copy_if(this->schedule_items_.begin(),this->schedule_items_.end(),std::back_inserter(of_room.schedule_items_),[sch_room_id](SchedulingItem index){
            return (index.RoomId()==sch_room_id);
        } );
        return of_room;
    }

    Schedule Schedule::OfYear(int sch_year) const {
        Schedule of_year;
        std::copy_if(this->schedule_items_.begin(),this->schedule_items_.end(),std::back_inserter(of_year.schedule_items_),[sch_year](SchedulingItem index){
            return (index.Year()==sch_year);
        } );
        return of_year;
    }


    void Schedule::InsertScheduleItem(const SchedulingItem &item) {
        schedule_items_.push_back(item);
    }

    std::size_t Schedule::Size() const {
        return schedule_items_.size();
    }

    SchedulingItem Schedule::operator[](int index) const {
        return schedule_items_[index];
    }

    std::vector<int> Schedule::AvailableTimeSlots(int n_time_slots) const {
        std::vector<int> available;
        std::vector<int> unavailable;
        std::vector<int> all;

        int i(1);
        while(i<=n_time_slots) {
            all.push_back(i);

            for(const auto &j : schedule_items_) {
                if(j.TimeSlot() == i) {
                    unavailable.push_back(i);
                    break;
                }
            }

            if(std::find(unavailable.begin(), unavailable.end(), i)==unavailable.end()){
                available.push_back(i);
            }
            i++;
        }

        return available;
    }


    Schedule GreedyScheduler::PrepareNewSchedule(const std::vector<int> &classrooms,
                                                 const std::map<int, std::vector<int>> &teacher_courses_assignment,
                                                 const std::map<int, std::set<int>> &courses_of_year,
                                                 int n_time_slots) {

        Schedule schedule;
        
        std::map<int, std::vector<int>>::const_iterator teacher_ca_it;
        for (teacher_ca_it = teacher_courses_assignment.begin(); teacher_ca_it != teacher_courses_assignment.end(); teacher_ca_it++){
            if(teacher_ca_it->second.size()>=n_time_slots){
                throw NoViableSolutionFound();
            }
            int  sch_room_id(0), sch_time_id(0), sch_year(0);
            for (auto teacher_ca_vec_it : teacher_ca_it->second){

                int sch_course_id = teacher_ca_vec_it;
                bool okay=false;
                
                for (auto courses_year_it : courses_of_year){

                    if(courses_year_it.second.size()>=n_time_slots){
                        throw NoViableSolutionFound();
                    }

                    std::set<int> id_of_courses=courses_year_it.second;

                    for (auto id_of_one_course : id_of_courses){
                        if (id_of_one_course == sch_course_id){
                            okay=true;
                            sch_year=courses_year_it.first;
                            break;
                        }
                    }
                    if(okay) {
                        break;
                    }
                }
               if (!okay){
                    throw NoViableSolutionFound();
               }

               for (auto classrooms_it : classrooms){
                    std::vector<int> available_timetable_of_room=schedule.OfRoom(classrooms_it).AvailableTimeSlots(n_time_slots);

                    for (auto available_room_time_it : available_timetable_of_room ){
                            sch_time_id = available_room_time_it;
                            sch_room_id = classrooms_it;
                    }
               }
                schedule.InsertScheduleItem({sch_course_id,teacher_ca_it->first,sch_room_id,sch_time_id,sch_year});
            }
        }
        return schedule;
    }
}
