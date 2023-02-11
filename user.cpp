#include "user.h"

const string &User::getNombre() const
{
    return nombre;
}

void User::setNombre(const string &newNombre)
{
    nombre = newNombre;
}

const string &User::getApelllido() const
{
    return apelllido;
}

void User::setApelllido(const string &newApelllido)
{
    apelllido = newApelllido;
}

float User::getMontoIngreso() const
{
    return montoIngreso;
}

void User::setMontoIngreso(float newMontoIngreso)
{
    montoIngreso = newMontoIngreso;
}

float User::getMontoEgreso() const
{
    return montoEgreso;
}

void User::setMontoEgreso(float newMontoEgreso)
{
    montoEgreso = newMontoEgreso;
}

User::User():montoIngreso(0), montoEgreso(0){}

