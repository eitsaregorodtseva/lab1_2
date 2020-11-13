#ifndef NOTE_H
#define NOTE_H
#include <vector>
#include <string>

using namespace std;

class Note {
public:
    static constexpr double WATER_MIN = 1;
    static constexpr double WATER_MAX = 2;
    Note() = default;
    Note(const vector<unsigned int>& data_info, const vector<string>& student_info,
         const double water_number);
    Note(const Note& copy);
    vector<unsigned int> getDate() const;
    vector<string> getStudent() const;
    double getWaterNumber() const;
    void setData(const vector<unsigned int>& data_info);
    void setStudent(const vector<string>& student_info);
    void setWaterNumber(const double water_number);
    ~Note() = default;

private:
    vector<unsigned int> date_info_; //Год Месяц День
    vector<string> student_info_;
    double water_number_;
};

#endif // NOTE_H
