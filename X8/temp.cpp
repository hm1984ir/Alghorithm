enum class human_color : int;
enum class human_style{tall,fat,slim};


int main(){
    auto c = human_color::black;

    auto cc = human_style::tall;
}

enum class human_color : int{
    black = 1,
    red = 2,
    white = 3,
    yellow = 4
};
