#ifndef DATACOLLECTOR_HPP
#define DATACOLLECTOR_HPP

#include <QString>

#include "menus_helpers.hpp"

// Singleton pattern used
class DataCollector
{
public:
    // Singleton pattern realization
    DataCollector(DataCollector &other) = delete;
    DataCollector& operator=(const DataCollector&) = delete;
    static DataCollector *GetInstance();
    virtual ~DataCollector();

public:
    // Getters
    const QString getBgImageStr() const;
    Languages getLanguage() const;

    //Setters

private:
    explicit DataCollector();

    void init();

private:
    // Singleton pattern realization
    static DataCollector* _DataCollector;

    // Settings data
    QString    _bgImageStr;
    Languages  _language;

    // Game data
};

#endif // DATACOLLECTOR_HPP
