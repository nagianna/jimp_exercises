#ifndef JIMP2_SERIALIZATION_H
#define JIMP2_SERIALIZATION_H

#include <string>
#include <vector>
#include <functional>
#include <ostream>
#include<iostream>

#include <initializer_list>
#include <sstream>

#include <experimental/optional>
#include <memory>

namespace academia {
    class Serializer;

    class Serializable {
    public:
        virtual void Serialize(Serializer *serializer) = 0;
        virtual void Serialize(Serializer *serializer) const = 0;
    };

    class Room : public Serializable {
    public:
        enum class Type {
            COMPUTER_LAB,
            LECTURE_HALL,
            CLASSROOM
        };
        Room (int id, const std::string roomName, Type type);
        void Serialize(Serializer *serializer) override;
        void Serialize(Serializer *serializer) const override;
        std::string roomTypeToString(Type type) const;
    private:
        int mId;
        std::string mRoomName;
        Type mRoomType;
    };

    class Building : public Serializable{
    public:
        Building(int id, const std::string buildingName, const std::vector<std::reference_wrapper<const Serializable>> &rRooms);
        void Serialize(Serializer *serializer) override;
        void Serialize(Serializer *serializer) const override;
        int Id() const;

        int mId;
        std::string mBuildingName;
        const std::vector<std::reference_wrapper<const Serializable>> mRoomsVector;
    };

    class Serializer {
    public:
        Serializer(std::ostream *out);
        virtual void IntegerField(const std::string &field_name, int value) = 0;
        virtual void DoubleField(const std::string &field_name, double value) = 0;
        virtual void StringField(const std::string &field_name, const std::string &value) = 0;
        virtual void BooleanField(const std::string &field_name, bool value) = 0;
        virtual void SerializableField(const std::string &field_name, const Serializable &value) = 0;
        virtual void ArrayField(const std::string &field_name,
                                const std::vector<std::reference_wrapper<const Serializable>> &value) = 0;
        virtual void Header(const std::string &object_name) = 0;
        virtual void Footer(const std::string &object_name) = 0;
    protected:
        std::ostream *pSerializerOut;
    };

    class JsonSerializer : public Serializer{
    public:
        JsonSerializer(std::ostream *out);
        void IntegerField(const std::string &field_name, int value) override;
        void DoubleField(const std::string &field_name, double value) override;
        void StringField(const std::string &field_name, const std::string &value) override;
        void BooleanField(const std::string &field_name, bool value) override;
        void SerializableField(const std::string &field_name, const Serializable &value) override;
        void ArrayField(const std::string &field_name,
                        const std::vector<std::reference_wrapper<const Serializable>> &value) override;
        void Header(const std::string &object_name) override;
        void Footer(const std::string &object_name) override;
        void IsStreamEmpty();
    private:
        bool mStreamIsEmpty = true;
    };

    class XmlSerializer: public Serializer{
    public:

        XmlSerializer(std::ostream *out);

        void IntegerField(const std::string &field_name, int value) override;
        void DoubleField(const std::string &field_name, double value) override;
        void StringField(const std::string &field_name, const std::string &value) override;
        void BooleanField(const std::string &field_name, bool value) override;
        void SerializableField(const std::string &field_name, const academia::Serializable &value) override;
        void ArrayField(const std::string &field_name,
                        const std::vector<std::reference_wrapper<const academia::Serializable>> &value) override;
        void Header(const std::string &object_name) override;
        void Footer(const std::string &object_name) override;

    private:
    };



    class BuildingRepository{
    public:
        BuildingRepository();
        BuildingRepository(const std::initializer_list<Building> &building_list):building_list_(building_list){};
        ~BuildingRepository();
        void StoreAll(Serializer *serializer) const;
        std::experimental::optional<Building> operator[](int id) const;
        void Add(const Building &building);
    private:
        std::vector<Building> building_list_;
    };
}
















#endif //JIMP2_SERIALIZATION_H