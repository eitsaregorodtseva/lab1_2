#ifndef COLLECTION_H
#define COLLECTION_H

#include "note.h"
#include <memory>

using namespace std;

class Collection{
public:
    Collection();
    Collection(size_t n);
    Collection(const Collection& copy);    
    void pushBack(const Note& note);
    Note& searchIndex(size_t n);
    size_t size() const;
    Collection& copyOperator(const Collection& copy);
    void checkData();
    void checkLogic();
    void clear();
    void erase(size_t n);
    void writeToFile(string filename);
    void readFromFile(string filename);
    ~Collection() = default;

private:
    unique_ptr<Note[]> m_data;
    size_t m_size;
    size_t m_allocated;
    void copyFromCopy(const Collection& copy);

};

#endif // COLLECTION_H
