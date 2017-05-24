#include <stdio.h>

int main()
{
//----------------------简单预处理-----------------------------
//1. normal
	{
#if __WIN32__
		printf("win32\n");
#elif __linux__
		printf("linux\n");
#endif
	}

//2. 自定义, #if 后为常量表达式
	{
		int a = 0;
#if a
		printf("a = %d\n", a);
#else
		printf("a = %d\n", a);
#endif
	}

//3. ifdef
	{
#define GLOBAL

#ifdef GLOBAL
	printf("GLOBAL\n");
#else
	printf("NO GLOBAL\n");
#endif
	}

//4. ifndef
	{
#define GLOBAL
#define TWOBAL

#ifdef GLOBAL
#undef GLOBAL
#endif
#ifdef GLOBAL
	printf("GLOBAL\n");
#ifdef TWOBAL
	printf("NO GLOBAL\n");
#endif
#endif
	}

//5. #error
	{
		int a = 0;
#if a
#error hello world, dont output -------
		printf("----------\n");
#else
		printf("do not go #error\n");
#endif
	}

//6. ifdef <==> #if (defined)
	{
#define TOMADE
#define TODAY

#if (defined TOMADE)
		printf("defined tomade\n");
#ifdef TODAY
		printf("defined today\n");
#elif (defined YESTODAY)
		printf("defined yestoday\n");
#endif
#endif
	}

//------------------复杂的预处理------------------------------
//7. # 将宏参数字符串化
	{
#define DEBUG(string) #string
		printf("%s\n", DEBUG(helloworld));
	}

//8. ## 连接符，将宏参数或者其他的串连接到一起
	{
#define __stringify(x...) #x
		printf("%s\n", __stringify(hello world));

typedef int mode_t;

		struct device {
			int no;
		};

		struct attribute {
			const char        *name;
			struct module     *owner;
			mode_t            mode;
		};

		struct device_attribute {
			struct attribute attr;
			ssize_t (*show)(struct device *dev, struct device_attribute *attr,
					char *buf);
			ssize_t (*store)(struct device *dev, struct device_attribute *attr,
					const char *buf, size_t count);
		};

#define __ATTR(_name,_mode,_show,_store) { \
	.attr = {.name = __stringify(_name), .mode = _mode }, \
	.show = _show,     \
	.store = _store,     \
	}

#define DEVICE_ATTR(_name, _mode, _show, _store) \
	struct device_attribute dev_attr_##_name = __ATTR(_name, _mode, _show, _store)
}

	return 0;
}
