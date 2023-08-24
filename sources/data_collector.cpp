#include "data_collector.hpp"
#include "defaults.hpp"

DataCollector::DataCollector()
{
    init();
}

DataCollector::~DataCollector()
{
}

// Singlton pattern realization
DataCollector *DataCollector::_DataCollector = nullptr;

DataCollector *DataCollector::GetInstance()
{
    if(_DataCollector == nullptr)
        _DataCollector = new DataCollector();

    return _DataCollector;
}

void DataCollector::init()
{
    _bgImageStr = DefaultData::BgImageStr;
    _language = DefaultData::Language;
}

// Getters
const QString DataCollector::getBgImageStr() const
{
    return _bgImageStr;
}

Languages DataCollector::getLanguage() const
{
    return _language;
}

// Setters
