#include<cstring>
#include "NasiString.h"

namespace nik{

    int NasiString::get_size(){
        return sz;
    }

    /**<
    void copy_string(const char* p1, char* p2){
        int length = std::strlen(p1);

        while(length > 0){
            *p2 = *p1;
            p2++;
            p1++;

            length--;
        }

        p2++;
        p2=0;
    }  */

    char* extend_string(char* p,int needed_storage){

        int new_len =(needed_storage * 2)+1;

        char* str {new char[new_len]};

        std::strcpy(str, p);

        delete[] p;

        return str;
    }

    NasiString::NasiString(const char* c) :
        sz{std::strlen(c)},
        ptr{(sz <= MAX_STRING_FAST_MODE_SIZE)? ch : new char[sz+1] },
        space{0}{
        std::strcpy(ptr,c);
    }

    void NasiString::Copy_From(const NasiString& str){
        if(str.sz <= MAX_STRING_FAST_MODE_SIZE){
            //RV:ptr{ch} is not correct "review this again"
            ptr = ch;
        } else {
            ptr = new char[str.sz];
            //copy_string(str.ptr, ptr, str.sz);
        }

        std::strcpy(str.ptr, ptr);

        sz = str.sz;
        space = str.space;
    }

    void NasiString::Move_From(NasiString& str){
        if(str.sz <= MAX_STRING_FAST_MODE_SIZE){
            ptr = ch;
            std::strcpy(str.ptr, ptr);
            *str.ptr = 0;
        } else {
            //RV: ptr{str.ptr} is not correct!
            ptr = str.ptr;
        }

        sz = str.sz;
        space = str.space;
        str.ptr = nullptr;
    }

    NasiString::NasiString(const NasiString& str){
        Copy_From(str);
    }

    NasiString& NasiString::operator=(const NasiString& str){
        if(&str == this)
            return *this;

        if(sz > MAX_STRING_FAST_MODE_SIZE){
            delete[] ptr;
        }

        Copy_From(str);

        return *this;
    }

    NasiString& NasiString::operator+(const char* c){
        int len = std::strlen(c);

        if(len+sz <= MAX_STRING_FAST_MODE_SIZE){
            for(;sz<sz+len;sz++,c++){
                ch[sz-1] = *c;
            }

        } else {
            if(sz+len <= space){
                char* p{ptr+len};

                std::strcpy(p,ptr);
                p+=sz;//remove /0
                std::strcpy(p,c);

                space-=len;

            } else {
                char* p = extend_string(ptr, sz+len);
                ptr = p;
                p+=sz;//remove /0
                std::strcpy(p,c);

                space = std::strlen(ptr) - (sz+len);
            }
        }

        sz+=len;

        return *this;

    }

    NasiString::NasiString(NasiString&& str){
        Move_From(str);
    }

    NasiString& NasiString::operator=(NasiString&& str){
        Move_From(str);

        return *this;
    }

    char NasiString::operator[](int index){
        char* p {ptr};
        p+=index;
        return *p;
    }

    NasiString::~NasiString(){
        if(sz > MAX_STRING_FAST_MODE_SIZE){
            delete[] ptr;
        }
    }

}

