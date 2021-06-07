// helper.h
#pragma once

#define MAKE_SINGLENTON(classname)								\
		private:												\
			classname() {}										\
		public:													\
			classname(const classname&) = delete;				\
			classname& operator=(const classname&) = delete;	\
		public:													\
			static classname& getInstance()						\
			{													\
				static classname instance;						\
				return instance;								\
			}
