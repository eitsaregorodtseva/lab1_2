#include "collection.h"
#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>

using namespace std;

Collection::Collection() {
    this->m_size = 0;
    this->m_allocated = 0;
    this->m_data = nullptr;
}

Collection::Collection(size_t n) {
    this->m_size = n;
    this->m_data.reset(new Note[this->m_size]);
    this->m_allocated = this->m_size;
}

Collection::Collection(const Collection &copy) {
    this->m_size = copy.m_size;
    this->m_data.reset(new Note[this->m_size]);
    this->m_allocated = this->m_size;
    for (size_t i = 0; i < this->m_size; i++) {
        this->m_data[i] = copy.m_data[i];
    }
}

void Collection::checkData() const {
    Note tmp_data;
    for (size_t i = 0; i < this->m_size; ++i) {
        tmp_data = searchIndex(i);
        if (Note::WATER_MIN <= tmp_data.getWaterNumber() &&
                tmp_data.getWaterNumber() <= Note::WATER_MAX)
            cout << "No care errors." << endl;
        else
            cout << "Care errors found." << endl;
    }
}

void Collection::checkLogic() const {
    vector<vector<unsigned int>> sort_date, unsort_date;
    Note tmp_data;
    for (size_t i = 0; i <this-> m_size; ++i) {
        tmp_data = searchIndex(i);
        sort_date.push_back(tmp_data.getDate());
        unsort_date.push_back(tmp_data.getDate());
    }
    sort(sort_date.begin(), sort_date.end());
    if (sort_date == unsort_date)
        cout << "No logic mistakes." << endl;
    else
        cout << "Logic mistakes found." << endl;
}

void Collection::writeToFile(string filename) const {
    ofstream file (filename);
    Note tmp_data;
    if (file.is_open()) {
        file << this->m_size << endl;
        for (size_t i = 0; i < this->m_size; ++i) {
            tmp_data = this->searchIndex(i);
            for (size_t j = 0; j < tmp_data.getDate().size(); ++j)
                file << tmp_data.getDate()[j] << endl;
            for (size_t j = 0; j < tmp_data.getStudent().size(); ++j)
                file << tmp_data.getStudent()[j] << endl;
            file << tmp_data.getWaterNumber() << endl;
        }
    }
    file.close();
}

void Collection::readFromFile(string filename) {
    ifstream file (filename);
    size_t n;
    Note tmp_data;
    vector<unsigned int> tmp_date;
    vector<string> tmp_student;
    string buffer_string;
    size_t buffer_integer;
    if (file.is_open()) {
        file >> n;
        for (size_t i = 0; i < n; ++i) {
            for (size_t j = 0; j < 3; ++j) {
                file >> buffer_integer;
                tmp_date.push_back(buffer_integer);
            }
            for (size_t j = 0; j < 3; ++j) {
                file >> buffer_string;
                tmp_student.push_back(buffer_string);
            }
            file >> buffer_integer;
            tmp_data.setWaterNumber(buffer_integer);
            tmp_data.setData(tmp_date);
            tmp_data.setStudent(tmp_student);
            tmp_date.clear();
            tmp_student.clear();
            this->pushBack(tmp_data);
        }
    }
    file.close();
}

size_t Collection::size() const {
    return this->m_size;
}

Note &Collection::searchIndex(size_t n) const {
    if (n >= this->m_size) {
        throw out_of_range("");
    }
    return this->m_data[n];
}

void Collection::pushBack(const Note &note) {
    if (this->m_size >= this->m_allocated) {
        this->m_allocated += 1;
        auto newMemory = new Note[this->m_allocated];
        for (size_t i = 0; i < this->m_size; ++i) {
            newMemory[i] = this->m_data[i];
        }
        this->m_data.reset(newMemory);
    }
    this->m_data[this->m_size] = note;
    ++this->m_size;
}

void Collection::erase(size_t n) {
    if (this->m_size > 0) {
        for (size_t i = n; i < this->m_size; ++i) {
            this->m_data[i] = this->m_data[i + 1];
        }
        --this->m_size;
    }
}

void Collection::clear() {
    this->m_data.reset();
    this->m_data = nullptr;
    this->m_size = 0;
}
