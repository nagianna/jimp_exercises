//
// Created by Ania on 2018-05-17.
//


#ifndef JIMP_EXERCISES_SCHEDULER_H
#define JIMP_EXERCISES_SCHEDULER_H

#include <vector>
#include <map>
#include <set>


namespace academia
{
    class SchedulingItem
    {
    private:
        int course_id_;
        int teacher_id_;
        int room_id_;
        int time_slot_;
        int year_;

    public:
        SchedulingItem();
        SchedulingItem(int course_id, int teacher_id, int room_id, int time_slot, int year);
        ~SchedulingItem();

        //metody const nie modyfikuja zmiennych nalezacych do obiektu (ale moga modyfikowac lokalne zmienne)
        int CourseId() const;
        int TeacherId() const;
        int RoomId() const;
        int TimeSlot() const;
        int Year() const;
    };


    class Schedule
    {
    private:
        std::vector<SchedulingItem> schedule_items_;

    public:
        Schedule OfTeacher(int teacher_id) const;
        Schedule OfRoom(int room_id) const;
        Schedule OfYear(int year) const;

        void InsertScheduleItem(const SchedulingItem &item);
        std::vector<int> AvailableTimeSlots(int n_time_slots) const;

        std::size_t Size() const;
        SchedulingItem operator[](int index) const;  //przeciazanie operatora indeksu
    };


    class Scheduler{
    public:
        virtual Schedule PrepareNewSchedule(const std::vector<int> &rooms, const std::map<int, std::vector<int>> &teacher_courses_assignment, const std::map<int, std::set<int>> &courses_of_year, int n_time_slots)=0;
    };

    class GreedyScheduler: public Scheduler{
    public:
        Schedule PrepareNewSchedule(const std::vector<int> &rooms, const std::map<int, std::vector<int>> &teacher_courses_assignment, const std::map<int, std::set<int>> &courses_of_year, int n_time_slots) override;
    };

    class NoViableSolutionFound{};
}


#endif //JIMP_EXERCISES_SCHEDULER_H