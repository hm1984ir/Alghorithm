#include "scanner.h"
#include<sstream>
#include<string>

namespace hm_mini_compiler{
    using std::string;

    class Parser{
    public:
        int calculate_expr(string& expr);
    private:


    };

    int Parser::calculate_expr(string& expr){
        Scanner scanner{expr};
        Token t = scanner.get_token();


        int Result;

        std::istringstream convert(t.value.c_str());

        if ( !(convert >> Result) )
            Result = 0;

        return Result;
    }

}
