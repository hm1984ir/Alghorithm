#include<vector>
#include<iostream>

namespace HM{
//I guess, it's not a concrete class because of using vector type internally
    class Histogram{
    public:
        class Error_out_of_range{};
        explicit Histogram(int low, int high);
        void add_number(int number);
        const std::vector<int>& get_numbers()const;
    private:
        int _l_bound;
        int _h_bound;
        std::vector<int> _numbers;
    };

    std::ostream& operator<<(std::ostream& os,const Histogram& h){
        for(const auto& v :h.get_numbers() ){
                for(int i=0; i<v;i++){
                    os << "-";
                }
            os << "\n";
        }

        return os;
    }

    Histogram::Histogram(int low, int high) : _l_bound{low},_h_bound{high}{}
    void Histogram::add_number(int number){
        if(number > _h_bound || number < _l_bound){
            throw Error_out_of_range();
        }

        _numbers.push_back(number);
    }

    const std::vector<int>& Histogram::get_numbers() const{
        return _numbers;
    }
}

