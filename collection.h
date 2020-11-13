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
    Note& searchIndex(size_t n) const;
    size_t size() const;
    void checkData() const;
    void checkLogic() const;
    void clear();
    void pushBack(const Note& note);
    void erase(size_t n);
    void writeToFile(string filename) const;
    void readFromFile(string filename);
    ~Collection() = default;

private:
    unique_ptr<Note[]> m_data;
    size_t m_size;
    size_t m_allocated;

};

#endif // COLLECTION_H
