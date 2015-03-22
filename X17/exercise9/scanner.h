#include<string>

namespace hm_mini_compiler{
    enum class Operation{add = 1, multiply = 2, divide = 3, sub = 4};
    enum class Token_Type{number = 1, operation = 2};
    struct Token{
            std::string value;
            Token_Type type;
            Token(const std::string& v, Token_Type t) : value{v}, type{t}{}
            //Token(std::string&& v, Token_Type t) : value {v},type{t}{}
        };
    class Scanner{
    public:
        explicit Scanner(const std::string& text);
        Token get_token();

    private:
        //static char operation [4] = {'+','*','/','-'};
        //I didn't see use const for a value type like char below???
        bool try_scan_number(std::string& str) ;
        bool try_scan_operation(std::string& str);

        std::string _text;
        int _cursor;
        int _text_len;

    };

    bool try_cast_to_operation(char c){
        switch(c){
        case '+':
        case '-':
        case '*':
        case '/':
            return true;
        }

        return false;
    }

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

    Scanner::Scanner(const std::string& text) : _text{text},_cursor{},_text_len{}{
        _text_len = _text.length();
    }

    Token Scanner::get_token(){
        std::string token_str;
        if(try_scan_number(token_str)){
            return Token(token_str, Token_Type::number);
        } else if(try_scan_operation(token_str)){
            return Token(token_str, Token_Type::operation);
        }

        return Token("$",{});
    }

    bool Scanner::try_scan_number(std::string& num) {
        int scanner_cursor = _cursor;

        while(scanner_cursor < _text_len){
            if(try_cast_to_number(_text[scanner_cursor])){
                scanner_cursor++;
            } else{
                break;
            }
        }

        if(_cursor == scanner_cursor){
            return false;
        }

        num = _text.substr(_cursor,scanner_cursor-_cursor+1);
        _cursor = scanner_cursor;

        return true;
    }

    bool Scanner::try_scan_operation(std::string& str){

        if(try_cast_to_operation(_text[_cursor])){
            str = _text[_cursor];
            _cursor++;
            return true;
        }

        return false;
    }
}
