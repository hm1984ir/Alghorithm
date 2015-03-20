#include<string>

namespace hm_mini_compiler{
    enum class Operation{add = 1, multiply = 2, divide = 3, sub = 4};
    enum class Token_Type{number = 1, operation = 2};
    class Scanner{
    public:
        struct Token{
            string value;
            Token_Type type;
            Token(string v, Token_Type t) : value{v}, type{t}{}
        };
        explicit Scanner(std::string text);
        std::string get_token() const;

    private:
        static char[4] operation {'+','*','/','-'};
        //I didn't see use const for a value type like char below???
        bool try_scan_number(std::string& str) const;
        bool try_scan_operation(std::string& str) const;

        std::string _text;
        int _cursor;
        int _text_len;

    };

    bool try_cast_to_number(char c){
        switch(c){
        case '0' :
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
            return true;
        }

        return false;
    }

    Scanner::Scanner(std::string text) : _text{text}{
        _text_len = std::string::length(text);
    }

    Token& Scanner::get_token(){
        string token_str;
        if(try_scan_number(&token_str)){
            return Token(token_str, Token_Type::number);
        } else if(try_scan_operation(token_str){
            //return Token(token_str, Token_Type::operation);
        }
    }

    bool Scanner::try_scan_numebr(std::string& num) const{
        int scanner_cursor = _cursor;

        while(scanner_cursor < _text_len){
            if(try_cast_to_number(_text[_cursor])){
                scanner_cursor++;
            } else{
                scanner_cursor--;
                break;
            }
        }

        if(_cursor > scanner_cursor){
            return false;
        }

        num = _text.substr(_cursor,scanner_cursor-_cursor+1);
        _cursor = scanner_cursor;

        return true;
    }

}
