#ifndef CONSOLELIST_H_INCLUDED
#define CONSOLELIST_H_INCLUDED

#include "Fnames.h"


class ConsoleList : public List
{
    public:
        ConsoleList();
        ConsoleList(const ConsoleList&);
        ~ConsoleList();
      virtual void newShow();
};




#endif // CONSOLELIST_H_INCLUDED
