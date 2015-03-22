#include "scanner.h"
#include<sstream>
#include<string>

namespace hm_mini_compiler{
    using std::string;

    class Parser{
    public:
        int calculate_expr(string& expr);
    private:
        Operation op;

    };

    int string_to_number(const char* c){
        int num;

        std::istringstream convert(c);

        if ( !(convert >> num) )
            num = 0;

        return num;
    }

    int Parser::calculate_expr(string& expr){
        int result;
        Scanner scanner{expr};

        //??????
        Token tttt {"  ",Token_Type::number};

        for(Token t = scanner.get_token(); t.value != "$";t = scanner.get_token()){
            if(t.type == Token_Type::number){
                if(static_cast<int>(op) != 0){
                    int num = string_to_number(t.value.c_str());
                    switch (op){
                        case Operation::add:
                            result += num;
                            break;
                        case Operation::sub:
                            result -= num;
                            break;
                    }
                } else {
                    result = string_to_number(t.value.c_str());
                }

                op = {};
            } else if(t.type == Token_Type::operation){
                switch(t.value[0]){
                case '+':
                    op = Operation::add;
                    break;
                case '-':
                    op = Operation::sub;
                    break;
                }
            }
        }

        return result;
    }

}
