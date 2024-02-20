#ifndef GVDIE_H_
#define GVDIE_H_

#include <iostream>
using namespace std;

class GVDie {
   public:
   	GVDie();
   	void Roll();
   	int GetValue();
   	void SetSeed(int seed);

    private:
      int myValue;
};

#endif /* GVDIE_H_ */ 