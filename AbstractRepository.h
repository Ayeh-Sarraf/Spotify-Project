

#ifndef SPOTIFY_PROJECT_ABSTRACTREPOSITORY_H
#define SPOTIFY_PROJECT_ABSTRACTREPOSITORY_H
#include <optional>

using namespace std;

template <typename T>
class AbstractRepository {
public:
    virtual string save(T entity) = 0;
    virtual bool remove(string id) = 0;
    virtual optional<T> search(string id) = 0;

    virtual ~AbstractRepository() {}
};
#endif
