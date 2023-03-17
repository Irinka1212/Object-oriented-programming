#pragma once

struct Timestamp
{
    int seconds = 0;
    int minutes = 0;
    int hours = 0;
};

struct Date
{
    Timestamp time;
    int day = 1;
    int month = 1;
    int year = 1;
};
