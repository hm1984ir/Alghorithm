#include<iostream>
#include<string>
#include<vector>

namespace Chrono{
    enum class Season {spring =1,summer=2,fall=3,winter=4};
    class Date{
    public:
        class Bad_date { };
        explicit Date(int yy={},Season ss={},int dd={});

        int get_year() const;
        Season get_season() const;
        int get_day() const;

        std::string to_string() const;

        Date& add_day(int n);
        Date& add_season(int n);
        Date& add_year(int n);

    private:
        bool is_valid();
        int d,y;
        Season s;
    };

    bool is_date(int d, Season s, int y){
        return (d>=0 && d<=30);
    }
    const Date& default_date(){
        static Date _default_date{1,Season::spring,1920};
        return _default_date;
    }

    bool operator==(const Date& d1, const Date& d2);
    bool operator!=(const Date& d1, const Date& d2);

    std::ostream& operator<<(std::ostream& os, const Date& d){}
    std::istream& operator>>(std::istream& is, Date& d){}

    Date::Date(int yy, Season ss, int dd) : y{yy}, s{ss}, d{dd}{
        if(y == 0) y = default_date().get_year();
        if(s == Season{}) s = default_date().get_season();
        if(d == 0) d = default_date().get_day();

        if(!is_valid()){
            throw Bad_date();
        }
    }

    bool Date::is_valid(){
        return is_date(d, s, y);
    }

    inline int Date::get_year() const{
        return y;
    }

    inline int Date::get_day() const{
        return d;
    }

    inline Season Date::get_season() const{
        return s;
    }

    Date& Date::add_season(int n){
        if(n<=0) return *this;

        n += static_cast<int>(s);

        if(n > 4){
            //nothing to do
            return *this;
        }

        s = static_cast<Season>(n);

        return *this;
    }

}

void fill(std::vector<Chrono::Date>& aa){
    while(std::cin){
        Chrono::Date d;
        try{
            std::cin >> d;
        } catch(Chrono::Date::Bad_date){
            continue;
        }

        aa.push_back(d);
    }
}

int main(){
    using namespace Chrono;
    std::string str;
    std::cin >> str;

    Date d {16,Season::spring,1394};

}
