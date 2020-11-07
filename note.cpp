#include "note.h"

Note::Note(const vector<unsigned int>& date_info, const vector<string>& student_info,
           const double water_number) {
    setData(date_info);
    setStudent(student_info);
    setWaterNumber(water_number);
};

Note::Note(const Note& copy) {
    setData(copy.getDate());
    setStudent(copy.getStudent());
    setWaterNumber(copy.getWaterNumber());
};

vector<unsigned int> Note::getDate() const {
    return date_info_;
};

vector<string> Note::getStudent() const {
    return student_info_;
};

double Note::getWaterNumber() const {
    return water_number_;
};

void Note::setData(const vector<unsigned int>& date_info) {
    date_info_ = date_info;
};

void Note::setStudent(const vector<string>& student_info) {
    student_info_ = student_info;
};

void Note::setWaterNumber(const double water_number) {
    water_number_ = water_number;
};
