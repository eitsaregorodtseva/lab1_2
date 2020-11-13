#include "note.h"
#include "tests.h"
#include "collection.h"
#include <iostream>
#include <assert.h>


size_t Equality(const Collection& collection_1_, const Collection& collection_2_) {
    Collection collection_1 = collection_1_, collection_2 = collection_2_;
    size_t error;
    if (collection_1.size() != collection_2.size())
        error = 1;
    else {
        if (collection_1.size() == 0)
            error = 0;
        else {
            for (size_t i = 0; i < collection_1.size(); ++i) {
                Note tmp_data_1 = collection_1.searchIndex(i);
                Note tmp_data_2 = collection_2.searchIndex(i);
                if (tmp_data_1.getDate() == tmp_data_2.getDate() &&
                        tmp_data_1.getStudent() == tmp_data_2.getStudent() &&
                        tmp_data_1.getWaterNumber() == tmp_data_2.getWaterNumber())
                    error = 0;
                else {
                    error = 1;
                    break;
                }
            }
        }
    }
    if (error == 1)
        cout << "Collections are not equal." << endl;
    else
        cout << "Collections are equal." << endl;
    return error;
}

void showData(const Collection& collection_) {
    Collection collection = collection_;
    for (size_t i = 0; i < collection.size(); ++i) {
        Note tmp_data;
        tmp_data = collection.searchIndex(i);
        cout << (i + 1) << " note:" << endl;
        for (size_t j = 0; j < tmp_data.getDate().size(); ++j)
            cout << tmp_data.getDate()[j] << endl;
        for (size_t j = 0; j < tmp_data.getStudent().size(); ++j)
            cout << tmp_data.getStudent()[j] << endl;
        cout << tmp_data.getWaterNumber() << endl;
        cout << endl;
    }
    cout << "The end of output.\n" << endl;
}

void testCopyConstructor(const Collection& collection_) {
    Collection collection = collection_;
    Collection collection_copy(collection_);
    assert(Equality(collection, collection_copy) == 0);
}

void testInitConstructor(const Collection& collection_) {
    Collection collection_example = collection_;
    Collection collection(collection_.size());
    assert(Equality(collection, collection_example) == 0);
}

void testPushBack(const Collection& collection_, const Note& note_) {
    Note note = note_;
    Collection collection = collection_;
    collection.pushBack(note);
    assert(note.getDate() ==
           collection.searchIndex(collection.size()-1).getDate());
    assert(note.getStudent() ==
           collection.searchIndex(collection.size()-1).getStudent());
    assert(note.getWaterNumber() ==
           collection.searchIndex(collection.size()-1).getWaterNumber());
}

void testErase(const Collection& collection_, size_t n) {
    Collection collection_1 = collection_, collection_2 = collection_;
    collection_1.erase(n);
    for (size_t i = 0; i < n; ++i) {
        Note tmp_data_1 = collection_1.searchIndex(i);
        Note tmp_data_2 = collection_2.searchIndex(i);
        assert(tmp_data_1.getDate() == tmp_data_2.getDate());
        assert(tmp_data_1.getStudent() == tmp_data_2.getStudent());
        assert(tmp_data_1.getWaterNumber() == tmp_data_2.getWaterNumber());
    }
    for (size_t i = n; i < collection_1.size(); ++i) {
        Note tmp_data_1 = collection_1.searchIndex(i);
        Note tmp_data_2 = collection_2.searchIndex(i+1);
        assert(tmp_data_1.getDate() == tmp_data_2.getDate());
        assert(tmp_data_1.getStudent() == tmp_data_2.getStudent());
        assert(tmp_data_1.getWaterNumber() == tmp_data_2.getWaterNumber());
    }

}

void testClear(const Collection& collection_) {
    Collection collection = collection_;
    collection.clear();
    assert(collection.size() == 0);
}

void testEquality(const Collection& collection_1_, const Collection& collection_2_) {
    Collection collection_1 = collection_1_, collection_2 = collection_2_;
    assert(collection_1.size() == collection_2.size());
    if (collection_1.size() == collection_2.size()) {
        for (size_t i = 0; i < collection_1.size(); ++i) {
            Note tmp_data_1 = collection_1.searchIndex(i);
            Note tmp_data_2 = collection_2.searchIndex(i);
            assert(tmp_data_1.getDate() == tmp_data_2.getDate());
            assert(tmp_data_1.getStudent() == tmp_data_2.getStudent());
            assert(tmp_data_1.getWaterNumber() == tmp_data_2.getWaterNumber());
        }
    }
}

void testFile(const Collection& collection_/*, const Note &note, size_t n*/) {
    string i_file = "input.txt";
    string o_file = "output.txt";
    Collection collection_1 = collection_, collection_2;
    collection_1.readFromFile(i_file);
    collection_1.writeToFile(o_file);
    cout << "Input and output is over." << endl;
    collection_2.readFromFile(o_file);
    showData(collection_1);
    showData(collection_2);
    assert(Equality(collection_1, collection_2) == 0);
    /*
    testCopyConstructor(collection_);
    testInitConstructor(collection_);
    testPushBack(collection_, note);
    testClear(collection_);
    testErase(collection_, n);
    */
}

void testCollection() {
    Collection collection_, collection_1_, collection_2_;
    /*
    vector<unsigned int> dataExample = {2000, 2, 3};
    vector<string> studentExample = {"FirstName", "LastName", "Patronymic", "3"};
    double water = 1.5;
    Note note_(dataExample, studentExample, water);
    */
    Note note_;
    size_t n = 0;
    testFile(collection_/*, note_, n*/);
    testCopyConstructor(collection_);
    testInitConstructor(collection_);
    testPushBack(collection_, note_);
    testClear(collection_);
    testErase(collection_, n);
    testEquality(collection_1_, collection_2_);
    cout << "All tests are passed." << endl;
}
