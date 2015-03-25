
namespace nik{
    class NasiString{
    public:
        explicit NasiString(const char*);
        static const int MAX_STRING_FAST_MODE_SIZE {15};

        NasiString(const NasiString&);
        NasiString& operator=(const NasiString&);

        NasiString(NasiString&&);
        NasiString& operator=(NasiString&&);

        int get_size();

        char operator[](int);

        NasiString& operator+(const char*);

        ~NasiString();

    private:
        char* ptr;
        int sz;

        union{
            char ch[MAX_STRING_FAST_MODE_SIZE+1];
            int space;
        };

        void Copy_From(const NasiString&);
        //RV: Move_From(NasiString&&);
        void Move_From(NasiString&);

    };
}
