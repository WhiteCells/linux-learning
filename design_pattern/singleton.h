#ifndef _SINGLETON_H_
#define _SINGLETON_H_

#include <mutex>

class Singleton {
public:
	static Singleton *getInstance() {
		if (nullptr == instance_) {
			m_mutex_.lock();
			if (nullptr == instance_) {
				instance_ = new Singleton();
			}
			m_mutex_.unlock();
		}
		return instance_;
	}
private:
	Singleton() {}
	static Singleton *instance_;
	static std::mutex m_mutex_;
}; 

#endif
