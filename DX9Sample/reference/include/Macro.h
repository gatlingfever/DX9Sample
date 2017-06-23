#ifndef __MACRO_H__
#define __MACRO_H__

#define DECLARE_SINGLETON(type)					\
	public:										\
		static type*& GetInstance(void)			\
		{										\
			static type* pInstance = nullptr;	\
			if(!pInstance)						\
				pInstance= new type;			\
			return pInstance;					\
		}										\
		static void DestroyInstance(void)		\
		{										\
			type* pInstance = GetInstance();	\
			if(pInstance)						\
			{									\
				delete pInstance;				\
				pInstance = nullptr;			\
			}									\
		}

#define GET_SINGLE(type) type::GetInstance()


#endif // !__MACRO_H__