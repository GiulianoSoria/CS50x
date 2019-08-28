// Helper functions for music

#include <cs50.h>
#include <math.h>
#include <string.h>
#include "helpers.h"

// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{

    int X = fraction[0] - '0';
    int Y = fraction[2] - '0';
    return ((8 * X) / Y);

}

// Calculates frequency (in Hz) of a note
int frequency(string note)
{

    int octave = note[strlen(note) - 1] - '0';

    int frequency;
    float f = 0;

    if (note[0] == 'A')
    {
        f = 440;
    }

    else if (note[0] == 'B')
    {
        f = (pow(2,(2.0 / 12.0))) * 440;
    }

    else if (note[0] == 'C')
    {
        f = (pow(2,(-9.0 / 12.0))) * 440;
    }

    else if (note[0] == 'D')
    {
        f = (pow(2,(-7.0 / 12.0))) * 440;
    }

    else if (note[0] == 'E')
    {
        f = (pow(2,(-5.0 / 12.0))) * 440;
    }

    else if (note[0] == 'F')
    {
        f = (pow(2,(-4.0 / 12.0))) * 440;
    }

    else if (note[0] == 'G')
    {
        f = (pow(2,(-2.0 / 12.0))) * 440;
    }

    if (note[1] == '#')
    {
        f = f * (pow(2,(1.0 / 12.0)));
    }

    if (note[1] == 'b')
    {
        f = f / ((pow(2,(1.0 / 12.0))));
    }

    if (octave < 4)
    {
        for (int i = 0; i < ((-octave) + 4); i++)
        {
            f = f / 2;
        }
    }

    if (octave > 4)
    {
        for (int i = 0; i < (octave - 4); i++)
        {
            f = f * 2;
        }
    }

    return frequency = round(f);

}


// Determines whether a string represents a rest
bool is_rest(string s)
{
    if (s[0] == '\0')
    {
        return true;
    }

    else
    {
        return false;
    }
}
