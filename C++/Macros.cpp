#include<iostream>
#include<cstring>

template<typename T>
T sq1(T x){ return x*x;}

template<typename Char>
Char AtImpl(Char const *string, int offset)
{
    return string[offset];
}
wchar_t wAt(wchar_t const * string, int offset)
{
    return AtImpl(string,offset);
}
char At(char const * string, int offset)
{
    return AtImpl(string, offset);
}

   class Department
   {
    public:
            static int const MaxEmployees=25;
   };

    enum class FileStatus
    {
        Ok=0,
        Error
    };
    enum class NetworkStatus
    {
        Warning=0,
        Error,
        Ok
    };
    bool statusOK(FileStatus status)
    {
        return status==FileStatus::Ok;
    }
    int main()
    {
        int i=2;
        i=sq1(3);
        i=sq1(i);
        i=sq1(1+2);// 1+2*1+2
        i=sq1(++i); //++i*++i
        double d=sq1(2.0);
        //auto s=sq1("Hello");

        auto c=wAt(L"Hello",2);
        auto j=Department::MaxEmployees;

       FileStatus fStatus=FileStatus::Ok;
       //fStatus++;
       if(fStatus==FileStatus::Error)
                j++;
       /* if(statusOK(NetworkStatus::Ok))
        {
            i++;
        }
        else
        {
            j++;
        }*/
    }