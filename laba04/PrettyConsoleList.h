#ifndef PRETTYCONSOLELIST_H
#define PRETTYCONSOLELIST_H

#include "ConsoleList.h"


class PrettyConsoleList : public ConsoleList
{
public:
    PrettyConsoleList();
    virtual ~PrettyConsoleList();
    virtual void newShow();
};

#endif
