#ifndef NA_PATTERN_SINGLETON
#define NA_PATTERN_SINGLETON

template<class InstanceType>
class Singleton{
private:
    static InstanceType* inst;
    static void createInst()
    {
        inst = new InstanceType();
    };
public:
    static InstanceType* Instance(){
        if(inst == nullptr)
        {
            createInst();
        }
        return inst;
    }
};

#endif // NA_PATTERN_SINGLETON
