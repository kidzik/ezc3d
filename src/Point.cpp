#define EZC3D_API_EXPORTS
///
/// \file Point.cpp
/// \brief Implementation of Point class
/// \author Pariterre
/// \version 1.0
/// \date October 17th, 2018
///

#include "Point.h"

ezc3d::DataNS::Points3dNS::Point::Point(const std::string &name) :
    _name(name)
{
    _data.resize(4);
}

ezc3d::DataNS::Points3dNS::Point::Point(const ezc3d::DataNS::Points3dNS::Point &p) :
    _name(p._name)
{
    _data.resize(4);
    x(p.x());
    y(p.y());
    z(p.z());
    residual(0);
}

void ezc3d::DataNS::Points3dNS::Point::print() const
{
    std::cout << name() << " = [" << x() << ", " << y() << ", " << z() << "]; Residual = " << residual() << std::endl;
}

void ezc3d::DataNS::Points3dNS::Point::write(std::fstream &f) const
{
    f.write(reinterpret_cast<const char*>(&_data[0]), ezc3d::DATA_TYPE::FLOAT);
    f.write(reinterpret_cast<const char*>(&_data[1]), ezc3d::DATA_TYPE::FLOAT);
    f.write(reinterpret_cast<const char*>(&_data[2]), ezc3d::DATA_TYPE::FLOAT);
    f.write(reinterpret_cast<const char*>(&_data[3]), ezc3d::DATA_TYPE::FLOAT);
}

const std::string& ezc3d::DataNS::Points3dNS::Point::name() const
{
    return _name;
}

void ezc3d::DataNS::Points3dNS::Point::name(const std::string &name)
{
    std::string name_copy = name;
    ezc3d::removeTrailingSpaces(name_copy);
    _name = name_copy;
}

const std::vector<float> ezc3d::DataNS::Points3dNS::Point::data() const
{
    return _data;
}

std::vector<float> ezc3d::DataNS::Points3dNS::Point::data_nonConst()
{
    return _data;
}

float ezc3d::DataNS::Points3dNS::Point::x() const
{
    return _data[0];
}

void ezc3d::DataNS::Points3dNS::Point::x(float x)
{
    _data[0] = x;
}

float ezc3d::DataNS::Points3dNS::Point::y() const
{
    return _data[1];
}

void ezc3d::DataNS::Points3dNS::Point::y(float y)
{
    _data[1] = y;
}

float ezc3d::DataNS::Points3dNS::Point::z() const
{
    return _data[2];
}

void ezc3d::DataNS::Points3dNS::Point::z(float z)
{
    _data[2] = z;
}


float ezc3d::DataNS::Points3dNS::Point::residual() const
{
    return _data[3];
}

void ezc3d::DataNS::Points3dNS::Point::residual(float residual){
    _data[3] = residual;
}
