
#ifndef __PARMENIDES_H__
#define __PARMENIDES_H__

/**
 * it does nothing, which means it does something
 */

class Parmenides {
public:
	Parmenides():
	  nothing(0),
	  something(0.0) {
		nothing = new int(5);
		something = 5.0;
	}

	double nextDoorToMadness() {
		return something - *nothing;
	}

	int getNothing() {
		return *nothing;
	}

	void setNothing(int i) {
		*nothing = i;
	}

	double getSomething() {
		return something;
	}

	void setSomething(double d) {
		something = d;
	}

	~Parmenides() {
		if (nothing) {
			delete nothing;
		}
	}

private:

	int * nothing;

	double something;

};

#endif // __PARMENIDES_H__
