#ifndef _SINGLETON_H_
#define _SINGLETON_H_

class Singleton {
public:
	Singleton(const Singleton &) = delete;
	Singleton &operator=(const Singleton &) = delete;
	static Singleton &getInstance() {
		static Singleton instance_;
		return instance_;
	}
private:
	Singleton() {}
};

#endif
