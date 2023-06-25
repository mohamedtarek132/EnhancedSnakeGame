#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <iostream>
using namespace sf;
using namespace std;

struct Check {
    //the snake to make sure that the snake didn't hit the walls or itself
    bool is_the_snake_alive;
    //to make sure that the player started playing 
    bool if_the_player_started_playing;
    //to make sure that the apple was eaten 
    bool is_the_apple_eaten;
    //to make sure that the rotten apple was eaten
    int is_the_rotten_apple_eaten;
    //to make sure that the setting button in game was pressed
    bool is_the_setting_in_game_button_pressed;
    //to make sure that the restart button was pressed
    bool is_the_restart_button_pressed;
    //to make sure that the start button was pressed
    bool is_start_button_pressed;
    //to make sure that the view high score button was pressed
    bool is_ranking_button_pressed;
    //to make sure that the setting button was pressed
    bool is_setting_button_pressed;
    //to make sure that the audio button in the settings menu was pressed
    bool is_audio_button_pressed;
    //to make sure that the opening ended
    bool did_the_opening_end;

    bool is_change_snake_button_pressed;

    bool is_snake_1_being_used;

    bool is_snake_2_being_used;

    bool is_snake_3_being_used;

    bool is_snake_4_being_used;

    bool is_snake_5_being_used;

    bool is_snake_6_being_used;

    bool is_snake_7_being_used;

    bool is_snake_8_being_used;

    bool is_snake_9_being_used;

    bool is_snake_10_being_used;

    bool is_snake_changing_colors;

    bool is_resize_button_pressed;

    bool is_survive_mode_pressed;

    bool is_new_story_mode_pressed;

    bool is_continue_story_mode_pressed;

    bool is_story_mode_pressed;

    bool is_main_menu_open;

    int is_mouse_pressed_once;

    int is_space_pressed_once;

    int number_of_snake_being_used;
};
struct shapetextures {
    Texture resumeicontexture;
    Texture restarticontexture;
    Texture snakeheadtexture;
    Texture rottenappletexture;
    Texture appletexture;
    Texture snaketurntexture;
    Texture snakebodytexture;
    Texture snaketailtexture;
    Texture exiticontexture;
    Texture opening_texture;
    Texture main_menu_page_texture;
    Texture setting_page_texture;
    Texture ranking_page_texture;
    Texture setting_music_page_texture;
    Texture exit_icon_in_setting_music_page_texture;
    Texture game_over_texture;
    Texture change_snake_page_texture;
    Texture Truee;
    Texture* resume_icon_texture;
    Texture* restart_icon_texture;
    Texture* apple_icon_texture;
    Texture* rotten_apple_icon_texture;
    Texture* snake_head_texture;
    Texture* exit_icon_texture;
    Texture* snake_turn_texture;
    Texture* snake_body_texture;
    Texture* snake_tail_texture;
    Texture game_mode_page_texture;
    Texture story_mode_page_texture;
};
struct shape {
    CircleShape apple_icon;
    CircleShape rotten_apple_icon;

    Sprite opening;
    Sprite main_menu_page;
    Sprite setting_page;
    Sprite ranking_page;
    Sprite setting_music_page;
    Sprite exit_icon_in_setting_music_page;
    Sprite game_over;
    Sprite change_snake_page;
    Sprite Tru_ee;
    Sprite game_mode_page;
    Sprite story_mode_page;

    RectangleShape pause_icon;
    RectangleShape resume_icon;
    RectangleShape restart_icon;
    RectangleShape exit_icon;
};

int window_width = 1300, window_height = 800;
// The maximum number of square for the snake
const int MAX_NUMBER_OF_SQUARES = 1000;

/* the speed array to make the snake parts to follow each other the 0 in the first dimension means its direction in the x axis and
 the 1 in the first dimension means its direction in the y axis*/
int speed[MAX_NUMBER_OF_SQUARES][2];
double screen_factor_x = 1;
double screen_factor_y = 1;
int story_level = 1;
//control the size of the snake
float snake_size_and_speed = 30;

Text text;

struct textures_of_snake
{
    Texture body___topleft;
    Texture body___bottomright;
    Texture body___bottomleft;
    Texture body___horizontal;
    Texture body___topright;
    Texture body___vertical;
    Texture head___down;
    Texture head___left;
    Texture head___right;
    Texture head___up;
    Texture tail___down;
    Texture tail___left;
    Texture tail___right;
    Texture tail___up;

    Texture* body_top_left;
    Texture* body_bottom_right;
    Texture* body_bottom_left;
    Texture* body_horizontal;
    Texture* body_top_right;
    Texture* body_vertical;
    Texture* head_down;
    Texture* head_left;
    Texture* head_right;
    Texture* head_up;
    Texture* tail_down;
    Texture* tail_left;
    Texture* tail_right;
    Texture* tail_up;

}snake_texture[10];


Sound apple_eating_sound, rotten_apple_eating_sound, losing_sound;

Music music;

RenderWindow window(VideoMode(window_width, window_height), "Snake Game");

RectangleShape snake[MAX_NUMBER_OF_SQUARES];

Texture game_background_texture;

Sprite game_background;

void sizenposition();

void collision(shape shapes, int& number_of_eaten_apples, Check& check, int ranking[], int& collision_counter);

void update_game(shape& shapes, int& counter, Check& check, int number_of_eaten_apples);

void snake_movement(Check& check);

void changexny();

void draw_game(shape& shapes, int& number_of_eaten_apples, Check& check, Font font, shapetextures texture);

void set_color(int square_number, int number_of_eaten_apples, Check check);

void set_texture(int number_of_eaten_apples, Check check, shapetextures& textures);

void randapple(shape& shapes, Check& check, int number_of_eaten_apples);

void randrottenapple(shape& shapes, Check& check, int number_of_eaten_apples);

void apple_counter(int number_of_eaten_apples, Check check);

void draw_resume_icon(shape shapes, Check check);

void draw_restart_icon(shape shapes, Check check);

void draw_exit_icon(shape shapes, Check check);

void drawMainMenu(Font& font, shape shapes, Check check);

void drawSettingsMenu(Font& font, shape shapes, Check check);

void draw_view_high_score_menu(shape shapes, Text text, int ranking[], Check check);

void changing_ranking(int number_of_eaten_apples, int ranking[]);

void draw_audio_settings(shape shapes, Check check);

void draw_change_color(shape shapes, Check& check);

void change_size(shape& shapes);

int main() {
    // a counter to make the snake move slower by decreasing the number of times the snake will move per second
    int game_counter = 0;
    // a counter to keep the opening playing for a second or two
    int opening_counter = 0;
    // the number of eaten apples in the game to make the snake grow taller
    int number_of_eaten_apples = 0;
    //to keep record of the highest 3 scores in the game
    int ranking[3] = {};

    int collision_counter = 0;
    //1 for check snake , 0 for if the player started playing, 0 for is the apple eaten,
    Check check = {};
    check.is_the_snake_alive = 1;
    check.is_snake_1_being_used = 1;

    shapetextures textures;

    shape shapes;

    SoundBuffer apple_eating_sound_buffer, rotten_apple_eating_sound_buffer, losing_sound_buffer;

    Font font;

    textures.resume_icon_texture = &textures.resumeicontexture;
    textures.restart_icon_texture = &textures.restarticontexture;
    textures.exit_icon_texture = &textures.exiticontexture;
    textures.apple_icon_texture = &textures.appletexture;
    textures.rotten_apple_icon_texture = &textures.rottenappletexture;
    textures.snake_head_texture = &textures.snakeheadtexture;

    //loading backgroung music
    music.openFromFile("Snake Game _music.wav");
    music.setLoop(true);
    music.play();
    music.setVolume(0);

    //loading fong and setting the font of the text
    font.loadFromFile("font file 2.ttf");
    text.setFont(font);

    //loading sound of the apple being eaten
    apple_eating_sound_buffer.loadFromFile("apple_crunch.wav");
    apple_eating_sound.setBuffer(apple_eating_sound_buffer);

    //loading sound of the rotten apple being eaten
    rotten_apple_eating_sound_buffer.loadFromFile("player_hurt.wav");
    rotten_apple_eating_sound.setBuffer(rotten_apple_eating_sound_buffer);

    //loading sound of the snake diying
    losing_sound_buffer.loadFromFile("gameover.wav");
    losing_sound.setBuffer(losing_sound_buffer);


    //loading textures

    //loading texture of the restart icon 
    textures.restarticontexture.loadFromFile("restart_button.png");
    textures.restarticontexture.setSmooth(1);
    shapes.restart_icon.setTexture(textures.restart_icon_texture);

    //loading texture of the resume icon 
    textures.resumeicontexture.loadFromFile("resume_button.png");
    textures.resumeicontexture.setSmooth(1);
    shapes.resume_icon.setTexture(textures.resume_icon_texture);

    //loading texture of the exit icon
    textures.exiticontexture.loadFromFile("exit_button.png");
    textures.exiticontexture.setSmooth(1);
    shapes.exit_icon.setTexture(textures.exit_icon_texture);

    //loading texture of the apple icon
    textures.appletexture.loadFromFile("apple.png", IntRect(0, 182, 61, 70));
    shapes.apple_icon.setTexture(textures.apple_icon_texture);

    //loading texture of the rotten apple
    textures.rottenappletexture.loadFromFile("rotten_apple-removebg-preview.png");
    shapes.rotten_apple_icon.setTexture(textures.rotten_apple_icon_texture);

    //loading texture of the game background
    game_background_texture.loadFromFile("Background.png");
    game_background.setTexture(game_background_texture);
    game_background.setScale((1300.0 / 1800.0), (800.0 / 1300.0));

    //loading textures for the snake
    textures.snakeheadtexture.loadFromFile("Snake sprite sheet.png", IntRect(0, 2, 40, 40));
    textures.snakeheadtexture.setSmooth(1);
    textures.snakebodytexture.loadFromFile("Snake sprite sheet.png", IntRect(84, 85, 40, 40));
    textures.snakebodytexture.setSmooth(1);
    textures.snaketurntexture.loadFromFile("Snake sprite sheet.png", IntRect(42, 0, 40, 40));
    textures.snaketurntexture.setSmooth(1);
    textures.snaketailtexture.loadFromFile("Snake sprite sheet.png", IntRect(44, 85, 40, 40));
    textures.snaketailtexture.setSmooth(1);


    //load the textures of the first snake
    snake_texture[0].body___topleft.loadFromFile("body top left(1).png");
    snake_texture[0].body___bottomright.loadFromFile("body bottom right(1).png");
    snake_texture[0].body___bottomleft.loadFromFile("body bottom left(1).png");
    snake_texture[0].body___horizontal.loadFromFile("body horizontal(1).png");
    snake_texture[0].body___topright.loadFromFile("body top right(1).png");
    snake_texture[0].body___vertical.loadFromFile("body vertical(1).png");
    snake_texture[0].head___down.loadFromFile("head bottom(1).png");
    snake_texture[0].head___left.loadFromFile("head left(1).png");
    snake_texture[0].head___right.loadFromFile("head right(1).png");
    snake_texture[0].head___up.loadFromFile("head top(1).png");
    snake_texture[0].tail___down.loadFromFile("tail bottom(1).png");
    snake_texture[0].tail___left.loadFromFile("tail left(1).png");
    snake_texture[0].tail___right.loadFromFile("tail right(1).png");
    snake_texture[0].tail___up.loadFromFile("tail top(1).png");
    snake_texture[0].body_top_left = &snake_texture[0].body___topleft;
    snake_texture[0].body_bottom_right = &snake_texture[0].body___bottomright;
    snake_texture[0].body_bottom_left = &snake_texture[0].body___bottomleft;
    snake_texture[0].body_horizontal = &snake_texture[0].body___horizontal;
    snake_texture[0].body_top_right = &snake_texture[0].body___topright;
    snake_texture[0].body_vertical = &snake_texture[0].body___vertical;
    snake_texture[0].head_down = &snake_texture[0].head___down;
    snake_texture[0].head_left = &snake_texture[0].head___left;
    snake_texture[0].head_right = &snake_texture[0].head___right;
    snake_texture[0].head_up = &snake_texture[0].head___up;
    snake_texture[0].tail_down = &snake_texture[0].tail___down;
    snake_texture[0].tail_left = &snake_texture[0].tail___left;
    snake_texture[0].tail_right = &snake_texture[0].tail___right;
    snake_texture[0].tail_up = &snake_texture[0].tail___up;
    //load the textures of the second snake
    snake_texture[1].body___topleft.loadFromFile("body top left(2).png");
    snake_texture[1].body___bottomright.loadFromFile("body bottom right(2).png");
    snake_texture[1].body___bottomleft.loadFromFile("body bottom left(2).png");
    snake_texture[1].body___horizontal.loadFromFile("body horizontal(2).png");
    snake_texture[1].body___topright.loadFromFile("body top right(2).png");
    snake_texture[1].body___vertical.loadFromFile("body vertical(2).png");
    snake_texture[1].head___down.loadFromFile("head bottom(2).png");
    snake_texture[1].head___left.loadFromFile("head left(2).png");
    snake_texture[1].head___right.loadFromFile("head right(2).png");
    snake_texture[1].head___up.loadFromFile("head top(2).png");
    snake_texture[1].tail___down.loadFromFile("tail bottom(2).png");
    snake_texture[1].tail___left.loadFromFile("tail left(2).png");
    snake_texture[1].tail___right.loadFromFile("tail right(2).png");
    snake_texture[1].tail___up.loadFromFile("tail top(2).png");
    snake_texture[1].body_top_left = &snake_texture[1].body___topleft;
    snake_texture[1].body_bottom_right = &snake_texture[1].body___bottomright;
    snake_texture[1].body_bottom_left = &snake_texture[1].body___bottomleft;
    snake_texture[1].body_horizontal = &snake_texture[1].body___horizontal;
    snake_texture[1].body_top_right = &snake_texture[1].body___topright;
    snake_texture[1].body_vertical = &snake_texture[1].body___vertical;
    snake_texture[1].head_down = &snake_texture[1].head___down;
    snake_texture[1].head_left = &snake_texture[1].head___left;
    snake_texture[1].head_right = &snake_texture[1].head___right;
    snake_texture[1].head_up = &snake_texture[1].head___up;
    snake_texture[1].tail_down = &snake_texture[1].tail___down;
    snake_texture[1].tail_left = &snake_texture[1].tail___left;
    snake_texture[1].tail_right = &snake_texture[1].tail___right;
    snake_texture[1].tail_up = &snake_texture[1].tail___up;

    //load the textures of the third snake
    snake_texture[2].body___topleft.loadFromFile("body top left(3).png");
    snake_texture[2].body___bottomright.loadFromFile("body bottom right(3).png");
    snake_texture[2].body___bottomleft.loadFromFile("body bottom left(3).png");
    snake_texture[2].body___horizontal.loadFromFile("body horizontal(3).png");
    snake_texture[2].body___topright.loadFromFile("body top right(3).png");
    snake_texture[2].body___vertical.loadFromFile("body vertical(3).png");
    snake_texture[2].head___down.loadFromFile("head bottom(3).png");
    snake_texture[2].head___left.loadFromFile("head left(3).png");
    snake_texture[2].head___right.loadFromFile("head right(3).png");
    snake_texture[2].head___up.loadFromFile("head top(3).png");
    snake_texture[2].tail___down.loadFromFile("tail bottom(3).png");
    snake_texture[2].tail___left.loadFromFile("tail left(3).png");
    snake_texture[2].tail___right.loadFromFile("tail right(3).png");
    snake_texture[2].tail___up.loadFromFile("tail top(3).png");
    snake_texture[2].body_top_left = &snake_texture[2].body___topleft;
    snake_texture[2].body_bottom_right = &snake_texture[2].body___bottomright;
    snake_texture[2].body_bottom_left = &snake_texture[2].body___bottomleft;
    snake_texture[2].body_horizontal = &snake_texture[2].body___horizontal;
    snake_texture[2].body_top_right = &snake_texture[2].body___topright;
    snake_texture[2].body_vertical = &snake_texture[2].body___vertical;
    snake_texture[2].head_down = &snake_texture[2].head___down;
    snake_texture[2].head_left = &snake_texture[2].head___left;
    snake_texture[2].head_right = &snake_texture[2].head___right;
    snake_texture[2].head_up = &snake_texture[2].head___up;
    snake_texture[2].tail_down = &snake_texture[2].tail___down;
    snake_texture[2].tail_left = &snake_texture[2].tail___left;
    snake_texture[2].tail_right = &snake_texture[2].tail___right;
    snake_texture[2].tail_up = &snake_texture[2].tail___up;

    //load the textures of the fourth snake
    snake_texture[3].body___topleft.loadFromFile("body top left(4).png");
    snake_texture[3].body___bottomright.loadFromFile("body bottom right(4).png");
    snake_texture[3].body___bottomleft.loadFromFile("body bottom left(4).png");
    snake_texture[3].body___horizontal.loadFromFile("body horizontal(4).png");
    snake_texture[3].body___topright.loadFromFile("body top right(4).png");
    snake_texture[3].body___vertical.loadFromFile("body vertical(4).png");
    snake_texture[3].head___down.loadFromFile("head bottom(4).png");
    snake_texture[3].head___left.loadFromFile("head left(4).png");
    snake_texture[3].head___right.loadFromFile("head right(4).png");
    snake_texture[3].head___up.loadFromFile("head top(4).png");
    snake_texture[3].tail___down.loadFromFile("tail bottom(4).png");
    snake_texture[3].tail___left.loadFromFile("tail left(4).png");
    snake_texture[3].tail___right.loadFromFile("tail right(4).png");
    snake_texture[3].tail___up.loadFromFile("tail top(4).png");
    snake_texture[3].body_top_left = &snake_texture[3].body___topleft;
    snake_texture[3].body_bottom_right = &snake_texture[3].body___bottomright;
    snake_texture[3].body_bottom_left = &snake_texture[3].body___bottomleft;
    snake_texture[3].body_horizontal = &snake_texture[3].body___horizontal;
    snake_texture[3].body_top_right = &snake_texture[3].body___topright;
    snake_texture[3].body_vertical = &snake_texture[3].body___vertical;
    snake_texture[3].head_down = &snake_texture[3].head___down;
    snake_texture[3].head_left = &snake_texture[3].head___left;
    snake_texture[3].head_right = &snake_texture[3].head___right;
    snake_texture[3].head_up = &snake_texture[3].head___up;
    snake_texture[3].tail_down = &snake_texture[3].tail___down;
    snake_texture[3].tail_left = &snake_texture[3].tail___left;
    snake_texture[3].tail_right = &snake_texture[3].tail___right;
    snake_texture[3].tail_up = &snake_texture[3].tail___up;

    //load the textures of the fifth snake
    snake_texture[4].body___topleft.loadFromFile("body top left(5).png");
    snake_texture[4].body___bottomright.loadFromFile("body bottom right(5).png");
    snake_texture[4].body___bottomleft.loadFromFile("body bottom left(5).png");
    snake_texture[4].body___horizontal.loadFromFile("body horizontal(5).png");
    snake_texture[4].body___topright.loadFromFile("body top right(5).png");
    snake_texture[4].body___vertical.loadFromFile("body vertical(5).png");
    snake_texture[4].head___down.loadFromFile("head bottom(5).png");
    snake_texture[4].head___left.loadFromFile("head left(5).png");
    snake_texture[4].head___right.loadFromFile("head right(5).png");
    snake_texture[4].head___up.loadFromFile("head top(5).png");
    snake_texture[4].tail___down.loadFromFile("tail bottom(5).png");
    snake_texture[4].tail___left.loadFromFile("tail left(5).png");
    snake_texture[4].tail___right.loadFromFile("tail right(5).png");
    snake_texture[4].tail___up.loadFromFile("tail top(5).png");
    snake_texture[4].body_top_left = &snake_texture[4].body___topleft;
    snake_texture[4].body_bottom_right = &snake_texture[4].body___bottomright;
    snake_texture[4].body_bottom_left = &snake_texture[4].body___bottomleft;
    snake_texture[4].body_horizontal = &snake_texture[4].body___horizontal;
    snake_texture[4].body_top_right = &snake_texture[4].body___topright;
    snake_texture[4].body_vertical = &snake_texture[4].body___vertical;
    snake_texture[4].head_down = &snake_texture[4].head___down;
    snake_texture[4].head_left = &snake_texture[4].head___left;
    snake_texture[4].head_right = &snake_texture[4].head___right;
    snake_texture[4].head_up = &snake_texture[4].head___up;
    snake_texture[4].tail_down = &snake_texture[4].tail___down;
    snake_texture[4].tail_left = &snake_texture[4].tail___left;
    snake_texture[4].tail_right = &snake_texture[4].tail___right;
    snake_texture[4].tail_up = &snake_texture[4].tail___up;

    //load the textures of the sixth snake
    snake_texture[5].body___topleft.loadFromFile("body top left(6).png");
    snake_texture[5].body___bottomright.loadFromFile("body bottom right(6).png");
    snake_texture[5].body___bottomleft.loadFromFile("body bottom left(6).png");
    snake_texture[5].body___horizontal.loadFromFile("body horizontal(6).png");
    snake_texture[5].body___topright.loadFromFile("body top right(6).png");
    snake_texture[5].body___vertical.loadFromFile("body vertical(6).png");
    snake_texture[5].head___down.loadFromFile("head bottom(6).png");
    snake_texture[5].head___left.loadFromFile("head left(6).png");
    snake_texture[5].head___right.loadFromFile("head right(6).png");
    snake_texture[5].head___up.loadFromFile("head top(6).png");
    snake_texture[5].tail___down.loadFromFile("tail bottom(6).png");
    snake_texture[5].tail___left.loadFromFile("tail left(6).png");
    snake_texture[5].tail___right.loadFromFile("tail right(6).png");
    snake_texture[5].tail___up.loadFromFile("tail top(6).png");
    snake_texture[5].body_top_left = &snake_texture[5].body___topleft;
    snake_texture[5].body_bottom_right = &snake_texture[5].body___bottomright;
    snake_texture[5].body_bottom_left = &snake_texture[5].body___bottomleft;
    snake_texture[5].body_horizontal = &snake_texture[5].body___horizontal;
    snake_texture[5].body_top_right = &snake_texture[5].body___topright;
    snake_texture[5].body_vertical = &snake_texture[5].body___vertical;
    snake_texture[5].head_down = &snake_texture[5].head___down;
    snake_texture[5].head_left = &snake_texture[5].head___left;
    snake_texture[5].head_right = &snake_texture[5].head___right;
    snake_texture[5].head_up = &snake_texture[5].head___up;
    snake_texture[5].tail_down = &snake_texture[5].tail___down;
    snake_texture[5].tail_left = &snake_texture[5].tail___left;
    snake_texture[5].tail_right = &snake_texture[5].tail___right;
    snake_texture[5].tail_up = &snake_texture[5].tail___up;

    //load the textures of the seventh snake
    snake_texture[6].body___topleft.loadFromFile("body top left(7).png");
    snake_texture[6].body___bottomright.loadFromFile("body bottom right(7).png");
    snake_texture[6].body___bottomleft.loadFromFile("body bottom left(7).png");
    snake_texture[6].body___horizontal.loadFromFile("body horizontal(7).png");
    snake_texture[6].body___topright.loadFromFile("body top right(7).png");
    snake_texture[6].body___vertical.loadFromFile("body vertical(7).png");
    snake_texture[6].head___down.loadFromFile("head bottom(7).png");
    snake_texture[6].head___left.loadFromFile("head left(7).png");
    snake_texture[6].head___right.loadFromFile("head right(7).png");
    snake_texture[6].head___up.loadFromFile("head top(7).png");
    snake_texture[6].tail___down.loadFromFile("tail bottom(7).png");
    snake_texture[6].tail___left.loadFromFile("tail left(7).png");
    snake_texture[6].tail___right.loadFromFile("tail right(7).png");
    snake_texture[6].tail___up.loadFromFile("tail top(7).png");
    snake_texture[6].body_top_left = &snake_texture[6].body___topleft;
    snake_texture[6].body_bottom_right = &snake_texture[6].body___bottomright;
    snake_texture[6].body_bottom_left = &snake_texture[6].body___bottomleft;
    snake_texture[6].body_horizontal = &snake_texture[6].body___horizontal;
    snake_texture[6].body_top_right = &snake_texture[6].body___topright;
    snake_texture[6].body_vertical = &snake_texture[6].body___vertical;
    snake_texture[6].head_down = &snake_texture[6].head___down;
    snake_texture[6].head_left = &snake_texture[6].head___left;
    snake_texture[6].head_right = &snake_texture[6].head___right;
    snake_texture[6].head_up = &snake_texture[6].head___up;
    snake_texture[6].tail_down = &snake_texture[6].tail___down;
    snake_texture[6].tail_left = &snake_texture[6].tail___left;
    snake_texture[6].tail_right = &snake_texture[6].tail___right;
    snake_texture[6].tail_up = &snake_texture[6].tail___up;

    //load the textures of the eighth snake
    snake_texture[7].body___topleft.loadFromFile("body top left(8).png");
    snake_texture[7].body___bottomright.loadFromFile("body bottom right(8).png");
    snake_texture[7].body___bottomleft.loadFromFile("body bottom left(8).png");
    snake_texture[7].body___horizontal.loadFromFile("body horizontal(8).png");
    snake_texture[7].body___topright.loadFromFile("body top right(8).png");
    snake_texture[7].body___vertical.loadFromFile("body vertical(8).png");
    snake_texture[7].head___down.loadFromFile("head bottom(8).png");
    snake_texture[7].head___left.loadFromFile("head left(8).png");
    snake_texture[7].head___right.loadFromFile("head right(8).png");
    snake_texture[7].head___up.loadFromFile("head top(8).png");
    snake_texture[7].tail___down.loadFromFile("tail bottom(8).png");
    snake_texture[7].tail___left.loadFromFile("tail left(8).png");
    snake_texture[7].tail___right.loadFromFile("tail right(8).png");
    snake_texture[7].tail___up.loadFromFile("tail top(8).png");
    snake_texture[7].body_top_left = &snake_texture[7].body___topleft;
    snake_texture[7].body_bottom_right = &snake_texture[7].body___bottomright;
    snake_texture[7].body_bottom_left = &snake_texture[7].body___bottomleft;
    snake_texture[7].body_horizontal = &snake_texture[7].body___horizontal;
    snake_texture[7].body_top_right = &snake_texture[7].body___topright;
    snake_texture[7].body_vertical = &snake_texture[7].body___vertical;
    snake_texture[7].head_down = &snake_texture[7].head___down;
    snake_texture[7].head_left = &snake_texture[7].head___left;
    snake_texture[7].head_right = &snake_texture[7].head___right;
    snake_texture[7].head_up = &snake_texture[7].head___up;
    snake_texture[7].tail_down = &snake_texture[7].tail___down;
    snake_texture[7].tail_left = &snake_texture[7].tail___left;
    snake_texture[7].tail_right = &snake_texture[7].tail___right;
    snake_texture[7].tail_up = &snake_texture[7].tail___up;

    //load the textures of the ninth snake
    snake_texture[8].body___topleft.loadFromFile("body(9).png");
    snake_texture[8].body___bottomright.loadFromFile("body(9).png");
    snake_texture[8].body___bottomleft.loadFromFile("body(9).png");
    snake_texture[8].body___horizontal.loadFromFile("body(9).png");
    snake_texture[8].body___topright.loadFromFile("body(9).png");
    snake_texture[8].body___vertical.loadFromFile("body(9).png");
    snake_texture[8].head___down.loadFromFile("head bottom(9).png");
    snake_texture[8].head___left.loadFromFile("head left(9).png");
    snake_texture[8].head___right.loadFromFile("head right(9).png");
    snake_texture[8].head___up.loadFromFile("head top(9).png");
    snake_texture[8].tail___down.loadFromFile("tail bottom(9).png");
    snake_texture[8].tail___left.loadFromFile("tail left(9).png");
    snake_texture[8].tail___right.loadFromFile("tail right(9).png");
    snake_texture[8].tail___up.loadFromFile("tail top(9).png");
    snake_texture[8].body_top_left = &snake_texture[8].body___topleft;
    snake_texture[8].body_bottom_right = &snake_texture[8].body___bottomright;
    snake_texture[8].body_bottom_left = &snake_texture[8].body___bottomleft;
    snake_texture[8].body_horizontal = &snake_texture[8].body___horizontal;
    snake_texture[8].body_top_right = &snake_texture[8].body___topright;
    snake_texture[8].body_vertical = &snake_texture[8].body___vertical;
    snake_texture[8].head_down = &snake_texture[8].head___down;
    snake_texture[8].head_left = &snake_texture[8].head___left;
    snake_texture[8].head_right = &snake_texture[8].head___right;
    snake_texture[8].head_up = &snake_texture[8].head___up;
    snake_texture[8].tail_down = &snake_texture[8].tail___down;
    snake_texture[8].tail_left = &snake_texture[8].tail___left;
    snake_texture[8].tail_right = &snake_texture[8].tail___right;
    snake_texture[8].tail_up = &snake_texture[8].tail___up;


    /*loading texture for the opening*/
    textures.opening_texture.loadFromFile("opening page.png");
    shapes.opening.setTexture(textures.opening_texture);
    shapes.opening.setScale((1300.0 / 1800.0), (800.0 / 1300.0));

    //loading texture for the main menu
    textures.main_menu_page_texture.loadFromFile("main menu.png");
    shapes.main_menu_page.setTexture(textures.main_menu_page_texture);
    shapes.main_menu_page.setScale((1300.0 / 1800), (800.0 / 1300));

    //loading texture for the setting page
    textures.setting_page_texture.loadFromFile("setting menu.png");
    textures.setting_page_texture.setSmooth(1);
    shapes.setting_page.setTexture(textures.setting_page_texture);
    shapes.setting_page.setScale((1300.0 / 1800), (800.0 / 1300.0));

    //loading texture for the setting music page
    textures.setting_music_page_texture.loadFromFile("Setting music page.png");
    shapes.setting_music_page.setTexture(textures.setting_music_page_texture);
    shapes.setting_music_page.setScale((1300.0 / 1800.0), (800.0 / 1300.0));

    //loading texture for the exit setting music 
    textures.exit_icon_in_setting_music_page_texture.loadFromFile("exit setting music page.png");
    shapes.exit_icon_in_setting_music_page.setTexture(textures.exit_icon_in_setting_music_page_texture);
    shapes.exit_icon_in_setting_music_page.setScale(0.7, 0.7);

    //loading texture for the ranking page
    textures.ranking_page_texture.loadFromFile("ranking page.png");
    shapes.ranking_page.setTexture(textures.ranking_page_texture);
    shapes.ranking_page.setScale((1300.0 / 1800.0), (800.0 / 1300.0));

    //loading texturer for the game over 
    textures.game_over_texture.loadFromFile("game_over.png");
    shapes.game_over.setTexture(textures.game_over_texture);
    shapes.game_over.setScale(0.2, 0.2);

    textures.change_snake_page_texture.loadFromFile("change snake.png");
    shapes.change_snake_page.setTexture(textures.change_snake_page_texture);

    textures.Truee.loadFromFile("true.png");
    shapes.Tru_ee.setTexture(textures.Truee);

    textures.game_mode_page_texture.loadFromFile("game mode.png");
    shapes.game_mode_page.setTexture(textures.game_mode_page_texture);
    shapes.game_mode_page.setScale((1300.0 / 1800), (800.0 / 1300));

    textures.story_mode_page_texture.loadFromFile("story mode.png");
    shapes.story_mode_page.setTexture(textures.story_mode_page_texture);
    shapes.story_mode_page.setScale((1300.0 / 1800), (800.0 / 1300));

    window.setFramerateLimit(70);

    sizenposition();

    //to keep the window open
    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            //to close the window with the close button
            if ((event.type == Event::Closed) || Keyboard::isKeyPressed(Keyboard::Escape))
                window.close();
            if (event.type == Event::Resized) {
                window.create(VideoMode(1300, 800), "Snake game", Style::Fullscreen);
                check.is_resize_button_pressed = 1;
                change_size(shapes);
                snake_size_and_speed = (int)(snake_size_and_speed * screen_factor_x);
            }
        }


        //to reset the game counter so it won't get past the integer limit
        if (game_counter == 1000000)
            game_counter = 0;
        if (collision_counter == 1000000)
            collision_counter == 1;
        //to make sure that the opening ended and that you won't press on any button while it is working
        if (check.did_the_opening_end)
            collision(shapes, number_of_eaten_apples, check, ranking, collision_counter);

        //to make sure that the snake didn't hit itself or the wall,that you didn't press on the in game setting,and that you pressed 
        //start
        if (check.is_start_button_pressed) {
            window.clear();
            window.draw(shapes.game_mode_page);
            window.display();
        }
        else if (check.is_story_mode_pressed) {
            window.clear();
            window.draw(shapes.story_mode_page);
            window.display();
        }
        else if (check.is_survive_mode_pressed) {
            if (check.is_the_snake_alive && !check.is_the_setting_in_game_button_pressed)
                update_game(shapes, game_counter, check, number_of_eaten_apples);

            else if (check.is_the_restart_button_pressed) {
                number_of_eaten_apples = 0;
                sizenposition();
                check.is_the_snake_alive = 1;
                check.if_the_player_started_playing = 0;
                check.is_the_restart_button_pressed = 0;
                check.is_the_setting_in_game_button_pressed = 0;
            }
            draw_game(shapes, number_of_eaten_apples, check, font, textures);
        }
        else if (opening_counter <= 200) {
            window.clear();
            window.draw(shapes.opening);
            window.display();
            opening_counter++;
        }
        else if (check.is_setting_button_pressed) {

            drawSettingsMenu(font, shapes, check);
        }
        else if (check.is_ranking_button_pressed)
        {
            draw_view_high_score_menu(shapes, text, ranking, check);

        }
        else if (check.is_audio_button_pressed) {
            draw_audio_settings(shapes, check);
        }
        else if (check.is_change_snake_button_pressed)
        {
            draw_change_color(shapes, check);
        }
        else {
            check.did_the_opening_end = 1;
            drawMainMenu(font, shapes, check);
            sizenposition();
            check.is_the_snake_alive = 1;
            check.if_the_player_started_playing = 0;
            check.is_the_restart_button_pressed = 0;
            check.is_the_setting_in_game_button_pressed = 0;
            number_of_eaten_apples = 0;
            check.is_main_menu_open = 1;

        }

    }
    return 0;
}

void change_size(shape& shapes) {
    shapes.main_menu_page.setScale(VideoMode::getDesktopMode().width / 1800.0, VideoMode::getDesktopMode().height / 1300.0);
    shapes.ranking_page.setScale(VideoMode::getDesktopMode().width / 1800.0, VideoMode::getDesktopMode().height / 1300.0);
    shapes.setting_page.setScale(VideoMode::getDesktopMode().width / 1800.0, VideoMode::getDesktopMode().height / 1300.0);
    shapes.opening.setScale(VideoMode::getDesktopMode().width / 1800.0, VideoMode::getDesktopMode().height / 1300.0);
    shapes.change_snake_page.setScale(VideoMode::getDesktopMode().width / 1300.0, VideoMode::getDesktopMode().height / 800.0);
    game_background.setScale(VideoMode::getDesktopMode().width / 1800.0, VideoMode::getDesktopMode().height / 1300.0);
    shapes.setting_music_page.setScale(VideoMode::getDesktopMode().width / 1800.0, VideoMode::getDesktopMode().height / 1300.0);
    shapes.restart_icon.setScale(1.5, 1.5);
    shapes.exit_icon.setScale(1.5, 1.5);
    shapes.resume_icon.setScale(1.5, 1.5);
    shapes.game_over.setScale(0.25, 0.25);
    shapes.exit_icon_in_setting_music_page.setScale(1, 1);
    screen_factor_x = VideoMode::getDesktopMode().width / 1300.0;
    screen_factor_y = VideoMode::getDesktopMode().height / 800.0;
    shapes.game_mode_page.setScale(VideoMode::getDesktopMode().width / 1800.0, VideoMode::getDesktopMode().height / 1300.0);
    shapes.story_mode_page.setScale(VideoMode::getDesktopMode().width / 1800.0, VideoMode::getDesktopMode().height / 1300.0);
    shapes.Tru_ee.setScale(screen_factor_x, screen_factor_y);
}

//to make all of the squares to have the same size, origin,and initial speed (+ve x direction) 
void sizenposition() {

    for (int i = 0; i < MAX_NUMBER_OF_SQUARES; i++) {
        snake[i].setSize(Vector2f(snake_size_and_speed, snake_size_and_speed));
        snake[i].setOrigin(snake_size_and_speed / 2, snake_size_and_speed / 2);
        snake[i].setPosition(Vector2f((int)(670 * screen_factor_x) + snake_size_and_speed * (2 - i), (386 * screen_factor_y)));
        speed[i][0] = snake_size_and_speed;
        speed[i][1] = 0;
    }
}

//to know whether the snake collided or not with the boundries,itself,apple,or rotten apple and to check that you pressed on 
//any button in the game
void collision(shape shapes, int& number_of_eaten_apples, Check& check, int ranking[], int& collision_counter) {

    bool left_or_right_mouse_button_pressed = Mouse::isButtonPressed(Mouse::Left);
    bool space_button_is_pressed = Keyboard::isKeyPressed(Keyboard::Space);
    bool escape_button_is_pressed = Keyboard::isKeyPressed(Keyboard::Escape);

    for (int i = 3; i < number_of_eaten_apples + 2; i++) {
        if (snake[0].getGlobalBounds().intersects(snake[i].getGlobalBounds()) && check.is_the_snake_alive == 1) {
            check.is_the_snake_alive = 0;
            losing_sound.play();
            changing_ranking(number_of_eaten_apples, ranking);
            break;
        }
    }
    bool did_snake_hit_right_side_of_the_box = ((int)snake[0].getGlobalBounds().left + (int)snake[0].getGlobalBounds().width) >=
        (int)(1157 * screen_factor_x);
    bool did_snake_hit_left_side_of_the_box = snake[0].getGlobalBounds().left <= (int)(145 * screen_factor_x);
    bool did_snake_hit_bottom_of_the_box = (int)(snake[0].getGlobalBounds().top + snake[0].getGlobalBounds().height) >=
        (int)(730 * screen_factor_y);
    bool did_snake_hit_top_of_the_box = snake[0].getGlobalBounds().top - snake_size_and_speed <= (int)(68 * screen_factor_y);

    if ((did_snake_hit_top_of_the_box || did_snake_hit_bottom_of_the_box || did_snake_hit_left_side_of_the_box ||
        did_snake_hit_right_side_of_the_box) && check.is_the_snake_alive == 1) {
        check.is_the_snake_alive = 0;
        changing_ranking(number_of_eaten_apples, ranking);
        losing_sound.play();
    }

    if (snake[0].getGlobalBounds().intersects(shapes.apple_icon.getGlobalBounds()) && check.is_the_apple_eaten == 0) {
        check.is_the_apple_eaten = 1;
        number_of_eaten_apples++;
        apple_eating_sound.play();
    }

    if (snake[0].getGlobalBounds().intersects(shapes.rotten_apple_icon.getGlobalBounds()) && check.is_the_rotten_apple_eaten == 0
        && number_of_eaten_apples > 0) {
        number_of_eaten_apples--;
        check.is_the_rotten_apple_eaten = 1;
        rotten_apple_eating_sound.play();
    }

    //in game buttons
    int icon_width = 765 - 580;
    int icon_height = 485 - 425;
    int in_game_buttons_x_position = 580;
    int in_game_first_button = 225;
    int in_game_space_between_buttons = 40;
    int in_game_second_button = in_game_first_button + icon_height + in_game_space_between_buttons;
    int in_game_third_button = in_game_second_button + icon_height + in_game_space_between_buttons;

    bool mouse_position_is_inside_resume_icon_box_in_game = 0;
    bool mouse_position_is_inside_restart_icon_box_in_game = 0;
    bool mouse_position_is_inside_exit_icon_box_in_game = 0;
    bool mouse_position_is_inside_pause_icon_box_in_game =
        Mouse::getPosition(window).x >= 1200 * screen_factor_x &&
        Mouse::getPosition(window).x <= 1300 * screen_factor_x &&
        Mouse::getPosition(window).y >= 5 * screen_factor_y &&
        Mouse::getPosition(window).y <= 75 * screen_factor_y;

    //main menu buttons

    int left_x_position_of_the_main_menu_buttons = 560;
    int width_of_main_menu_buttons = 190;
    int height_of_main_menu_buttons = 50;
    int first_button = 460;
    int space_between_main_menu_buttons = 45;
    int second_button = first_button + space_between_main_menu_buttons + height_of_main_menu_buttons;
    int third_button = second_button + space_between_main_menu_buttons + height_of_main_menu_buttons;
    int setting_icon_width = 145 - 30;
    int setting_icon_height = 755 - 670;
    int setting_icon_x_position = 30;
    int setting_icon_y_position = 670;

    bool mouse_position_is_inside_start_button_in_main_menu =
        Mouse::getPosition(window).x >= left_x_position_of_the_main_menu_buttons * screen_factor_x &&
        Mouse::getPosition(window).x <= (left_x_position_of_the_main_menu_buttons + width_of_main_menu_buttons) * screen_factor_x &&
        Mouse::getPosition(window).y >= first_button * screen_factor_y &&
        Mouse::getPosition(window).y <= (first_button + height_of_main_menu_buttons) * screen_factor_y;
    bool mouse_position_is_inside_view_high_score_button_in_main_menu =
        Mouse::getPosition(window).x >= left_x_position_of_the_main_menu_buttons * screen_factor_x &&
        Mouse::getPosition(window).x <= (left_x_position_of_the_main_menu_buttons + width_of_main_menu_buttons) * screen_factor_x &&
        Mouse::getPosition(window).y >= second_button * screen_factor_y &&
        Mouse::getPosition(window).y <= (second_button + height_of_main_menu_buttons) * screen_factor_y;

    bool mouse_position_is_inside_exit_button_in_main_menu =
        Mouse::getPosition(window).x >= left_x_position_of_the_main_menu_buttons * screen_factor_x &&
        Mouse::getPosition(window).x <= (left_x_position_of_the_main_menu_buttons + width_of_main_menu_buttons) * screen_factor_x &&
        Mouse::getPosition(window).y >= third_button * screen_factor_y &&
        Mouse::getPosition(window).y <= (third_button + height_of_main_menu_buttons) * screen_factor_y;

    bool mouse_position_is_inside_setting_button_in_main_menu =
        Mouse::getPosition(window).x >= setting_icon_x_position * screen_factor_x &&
        Mouse::getPosition(window).x <= (setting_icon_x_position + setting_icon_width) * screen_factor_x &&
        Mouse::getPosition(window).y >= setting_icon_y_position * screen_factor_y &&
        Mouse::getPosition(window).y <= (setting_icon_y_position + setting_icon_height) * screen_factor_y;

    //ranking buttons
    bool mouse_position_is_inside_exit_button_in_ranking_page =
        Mouse::getPosition(window).x >= 825 * screen_factor_x &&
        Mouse::getPosition(window).x <= 925 * screen_factor_x &&
        Mouse::getPosition(window).y >= 645 * screen_factor_y &&
        Mouse::getPosition(window).y <= 730 * screen_factor_y;

    //setting buttons
    int setting_buttons_x_position = 525;
    int setting_buttons_width = 780 - 525;
    int setting_buttons_height = 85;
    int setting_space_between_buttons = 15;
    int setting_first_button = 300;
    int setting_second_button = setting_first_button + setting_buttons_height + setting_space_between_buttons;
    int setting_third_button = setting_second_button + setting_buttons_height + setting_space_between_buttons;

    bool mouse_position_is_inside_audio_button_in_setting_page =
        Mouse::getPosition(window).x >= setting_buttons_x_position * screen_factor_x &&
        Mouse::getPosition(window).x <= (setting_buttons_x_position + setting_buttons_width) * screen_factor_x &&
        Mouse::getPosition(window).y >= setting_first_button * screen_factor_y &&
        Mouse::getPosition(window).y <= (setting_first_button + setting_buttons_height) * screen_factor_y;
    bool mouse_position_is_inside_change_color_button_in_setting_page =
        Mouse::getPosition(window).x >= setting_buttons_x_position * screen_factor_x &&
        Mouse::getPosition(window).x <= (setting_buttons_x_position + setting_buttons_width) * screen_factor_x &&
        Mouse::getPosition(window).y >= setting_second_button * screen_factor_y &&
        Mouse::getPosition(window).y <= (setting_second_button + setting_buttons_height) * screen_factor_y;
    bool mouse_position_is_inside_exit_button_in_setting_page =
        Mouse::getPosition(window).x >= setting_buttons_x_position * screen_factor_x &&
        Mouse::getPosition(window).x <= (setting_buttons_x_position + setting_buttons_width) * screen_factor_x &&
        Mouse::getPosition(window).y >= setting_third_button * screen_factor_y &&
        Mouse::getPosition(window).y <= (setting_third_button + setting_buttons_height) * screen_factor_y;
    //audio buttons
    bool mouse_position_is_inside_ON_Audio_in_audio_setting_page =
        Mouse::getPosition(window).x >= 615 * screen_factor_x &&
        Mouse::getPosition(window).x <= 683 * screen_factor_x &&
        Mouse::getPosition(window).y >= 390 * screen_factor_y &&
        Mouse::getPosition(window).y <= 445 * screen_factor_y;
    bool mouse_position_is_inside_OFF_Audio_in_setting_page =
        Mouse::getPosition(window).x >= 739 * screen_factor_x &&
        Mouse::getPosition(window).x <= 800 * screen_factor_x &&
        Mouse::getPosition(window).y >= 390 * screen_factor_y &&
        Mouse::getPosition(window).y <= 445 * screen_factor_y;
    bool mouse_position_is_inside_ON_Music_in_setting_page =
        Mouse::getPosition(window).x >= 615 * screen_factor_x &&
        Mouse::getPosition(window).x <= 683 * screen_factor_x &&
        Mouse::getPosition(window).y >= 523 * screen_factor_y &&
        Mouse::getPosition(window).y <= 576 * screen_factor_y;
    bool mouse_position_is_inside_OFF_Music_in_setting_page =
        Mouse::getPosition(window).x >= 739 * screen_factor_x &&
        Mouse::getPosition(window).x <= 800 * screen_factor_x &&
        Mouse::getPosition(window).y >= 523 * screen_factor_y &&
        Mouse::getPosition(window).y <= 576 * screen_factor_y;
    bool mouse_position_is_inside_exit_button_in_music_setting_page =
        Mouse::getPosition(window).x >= 845 * screen_factor_x &&
        Mouse::getPosition(window).x <= 925 * screen_factor_x &&
        Mouse::getPosition(window).y >= 255 * screen_factor_y &&
        Mouse::getPosition(window).y <= 330 * screen_factor_y;


    bool mouse_position_is_inside_Exit_in_change_color_page =
        Mouse::getPosition(window).x >= 25 * screen_factor_x &&
        Mouse::getPosition(window).x <= 120 * screen_factor_x &&
        Mouse::getPosition(window).y >= 690 * screen_factor_y &&
        Mouse::getPosition(window).y <= 785 * screen_factor_y;
    bool mouse_position_is_inside_first_snake_in_change_color_page =
        Mouse::getPosition(window).x >= 308 * screen_factor_x &&
        Mouse::getPosition(window).x <= 346 * screen_factor_x &&
        Mouse::getPosition(window).y >= 310 * screen_factor_y &&
        Mouse::getPosition(window).y <= 347 * screen_factor_y;
    bool mouse_position_is_inside_second_snake_in_change_color_page =
        Mouse::getPosition(window).x >= 387 * screen_factor_x &&
        Mouse::getPosition(window).x <= 423 * screen_factor_x &&
        Mouse::getPosition(window).y >= 310 * screen_factor_y &&
        Mouse::getPosition(window).y <= 347 * screen_factor_y;
    bool mouse_position_is_inside_third_snake_in_change_color_page =
        Mouse::getPosition(window).x >= 462 * screen_factor_x &&
        Mouse::getPosition(window).x <= 500 * screen_factor_x &&
        Mouse::getPosition(window).y >= 310 * screen_factor_y &&
        Mouse::getPosition(window).y <= 347 * screen_factor_y;
    bool mouse_position_is_inside_forth_snake_in_change_color_page =
        Mouse::getPosition(window).x >= 540 * screen_factor_x &&
        Mouse::getPosition(window).x <= 578 * screen_factor_x &&
        Mouse::getPosition(window).y >= 310 * screen_factor_y &&
        Mouse::getPosition(window).y <= 347 * screen_factor_y;
    bool mouse_position_is_inside_fifth_snake_in_change_color_page =
        Mouse::getPosition(window).x >= 616 * screen_factor_x &&
        Mouse::getPosition(window).x <= 654 * screen_factor_x &&
        Mouse::getPosition(window).y >= 310 * screen_factor_y &&
        Mouse::getPosition(window).y <= 347 * screen_factor_y;
    bool mouse_position_is_inside_sixth_snake_in_change_color_page =
        Mouse::getPosition(window).x >= 692 * screen_factor_x &&
        Mouse::getPosition(window).x <= 730 * screen_factor_x &&
        Mouse::getPosition(window).y >= 310 * screen_factor_y &&
        Mouse::getPosition(window).y <= 347 * screen_factor_y;
    bool mouse_position_is_inside_seventh_snake_in_change_color_page =
        Mouse::getPosition(window).x >= 765 * screen_factor_x &&
        Mouse::getPosition(window).x <= 804 * screen_factor_x &&
        Mouse::getPosition(window).y >= 310 * screen_factor_y &&
        Mouse::getPosition(window).y <= 347 * screen_factor_y;
    bool mouse_position_is_inside_eigth_snake_in_change_color_page =
        Mouse::getPosition(window).x >= 837 * screen_factor_x &&
        Mouse::getPosition(window).x <= 874 * screen_factor_x &&
        Mouse::getPosition(window).y >= 310 * screen_factor_y &&
        Mouse::getPosition(window).y <= 347 * screen_factor_y;
    bool mouse_position_is_inside_ninth_snake_in_change_color_page =
        Mouse::getPosition(window).x >= 905 * screen_factor_x &&
        Mouse::getPosition(window).x <= 944 * screen_factor_x &&
        Mouse::getPosition(window).y >= 310 * screen_factor_y &&
        Mouse::getPosition(window).y <= 347 * screen_factor_y;
    bool mouse_position_is_inside_tenth_snake_in_change_color_page =
        Mouse::getPosition(window).x >= 964 * screen_factor_x &&
        Mouse::getPosition(window).x <= 1002 * screen_factor_x &&
        Mouse::getPosition(window).y >= 310 * screen_factor_y &&
        Mouse::getPosition(window).y <= 347 * screen_factor_y;

    bool mouse_position_is_inside_first_color_option_in_change_color_page =
        Mouse::getPosition(window).x >= 591 * screen_factor_x &&
        Mouse::getPosition(window).x <= 630 * screen_factor_x &&
        Mouse::getPosition(window).y >= 453 * screen_factor_y &&
        Mouse::getPosition(window).y <= 489 * screen_factor_y;
    bool mouse_position_is_inside_second_color_option_in_change_color_page =
        Mouse::getPosition(window).x >= 736 * screen_factor_x &&
        Mouse::getPosition(window).x <= 775 * screen_factor_x &&
        Mouse::getPosition(window).y >= 452 * screen_factor_y &&
        Mouse::getPosition(window).y <= 491 * screen_factor_y;

    bool mouse_position_is_inside_story_button =
        Mouse::getPosition(window).x >= 520 * screen_factor_x &&
        Mouse::getPosition(window).x <= 795 * screen_factor_x &&
        Mouse::getPosition(window).y >= 320 * screen_factor_y &&
        Mouse::getPosition(window).y <= 410 * screen_factor_y;
    bool mouse_position_is_inside_survival_button =
        Mouse::getPosition(window).x >= 520 * screen_factor_x &&
        Mouse::getPosition(window).x <= 795 * screen_factor_x &&
        Mouse::getPosition(window).y >= 470 * screen_factor_y &&
        Mouse::getPosition(window).y <= (470 + (410 - 320)) * screen_factor_y;
    bool mouse_position_is_inside_exit_button_in_game_modes_page =
        Mouse::getPosition(window).x >= 5 * screen_factor_x &&
        Mouse::getPosition(window).x <= 115 * screen_factor_x &&
        Mouse::getPosition(window).y >= 700 * screen_factor_y &&
        Mouse::getPosition(window).y <= (790) * screen_factor_y;

    bool mouse_position_is_inside_continue_button_in_story_mode_page =
        Mouse::getPosition(window).x >= 770 * screen_factor_x &&
        Mouse::getPosition(window).x <= 1175 * screen_factor_x &&
        Mouse::getPosition(window).y >= 430 * screen_factor_y &&
        Mouse::getPosition(window).y <= (550) * screen_factor_y;
    bool mouse_position_is_inside_new_game_button_in_story_mode_page =
        Mouse::getPosition(window).x >= 770 * screen_factor_x &&
        Mouse::getPosition(window).x <= 1175 * screen_factor_x &&
        Mouse::getPosition(window).y >= 635 * screen_factor_y &&
        Mouse::getPosition(window).y <= (635 + 120) * screen_factor_y;
    bool mouse_position_is_inside_exit_button_in_story_mode_page =
        Mouse::getPosition(window).x >= 5 * screen_factor_x &&
        Mouse::getPosition(window).x <= 115 * screen_factor_x &&
        Mouse::getPosition(window).y >= 700 * screen_factor_y &&
        Mouse::getPosition(window).y <= (790) * screen_factor_y;;

    if (Mouse::isButtonPressed(Mouse::Right)) {
        cout << Mouse::getPosition(window).x << ' ' << Mouse::getPosition(window).y << endl;

    }
    if (left_or_right_mouse_button_pressed)
        check.is_mouse_pressed_once++;
    else
        check.is_mouse_pressed_once = 0;
    if (check.is_mouse_pressed_once > 1)
        left_or_right_mouse_button_pressed = 0;

    if (left_or_right_mouse_button_pressed)
        check.is_space_pressed_once++;
    else
        check.is_space_pressed_once = 0;
    if (check.is_space_pressed_once > 1)
        space_button_is_pressed = 0;

    if (check.is_the_snake_alive) {
        mouse_position_is_inside_resume_icon_box_in_game =
            Mouse::getPosition(window).x >= in_game_buttons_x_position * screen_factor_x &&
            Mouse::getPosition(window).x <= (in_game_buttons_x_position + icon_width) * screen_factor_x &&
            Mouse::getPosition(window).y >= in_game_first_button * screen_factor_y &&
            Mouse::getPosition(window).y <= (in_game_first_button + icon_height) * screen_factor_y;

        mouse_position_is_inside_restart_icon_box_in_game =
            Mouse::getPosition(window).x >= in_game_buttons_x_position * screen_factor_x &&
            Mouse::getPosition(window).x <= (in_game_buttons_x_position + icon_width) * screen_factor_x &&
            Mouse::getPosition(window).y >= in_game_second_button * screen_factor_y &&
            Mouse::getPosition(window).y <= (in_game_second_button + icon_height) * screen_factor_y;

        mouse_position_is_inside_exit_icon_box_in_game =
            Mouse::getPosition(window).x >= in_game_buttons_x_position * screen_factor_x &&
            Mouse::getPosition(window).x <= (in_game_buttons_x_position + icon_width) * screen_factor_x &&
            Mouse::getPosition(window).y >= in_game_third_button * screen_factor_y &&
            Mouse::getPosition(window).y <= (in_game_third_button + icon_height) * screen_factor_y;

    }
    else {
        mouse_position_is_inside_restart_icon_box_in_game =
            Mouse::getPosition(window).x >= 430 * screen_factor_x &&
            Mouse::getPosition(window).x <= (430 + icon_width) * screen_factor_x &&
            Mouse::getPosition(window).y >= 325 * screen_factor_y &&
            Mouse::getPosition(window).y <= (325 + icon_height) * screen_factor_y;

        mouse_position_is_inside_exit_icon_box_in_game =
            Mouse::getPosition(window).x >= 660 * screen_factor_x &&
            Mouse::getPosition(window).x <= (660 + icon_width) * screen_factor_x &&
            Mouse::getPosition(window).y >= 325 * screen_factor_y &&
            Mouse::getPosition(window).y <= (325 + icon_height) * screen_factor_y;

    }

    if (!check.is_the_setting_in_game_button_pressed && ((left_or_right_mouse_button_pressed &&
        mouse_position_is_inside_pause_icon_box_in_game) || space_button_is_pressed)) {
        check.is_the_setting_in_game_button_pressed = 1;
    }
    else if (check.is_survive_mode_pressed && !check.is_ranking_button_pressed
        && !check.is_setting_button_pressed && !check.is_audio_button_pressed && !check.is_change_snake_button_pressed) {

        if ((mouse_position_is_inside_resume_icon_box_in_game && left_or_right_mouse_button_pressed) ||
            space_button_is_pressed && check.is_the_setting_in_game_button_pressed) {
            check.is_the_setting_in_game_button_pressed = 0;
        }

        else if (mouse_position_is_inside_restart_icon_box_in_game && (check.is_the_snake_alive == 0 ||
            check.is_the_setting_in_game_button_pressed) && left_or_right_mouse_button_pressed) {
            check.is_the_restart_button_pressed = 1;
        }

        else if (mouse_position_is_inside_exit_icon_box_in_game && (check.is_the_snake_alive == 0
            || check.is_the_setting_in_game_button_pressed) && left_or_right_mouse_button_pressed) {
            check.is_survive_mode_pressed = 0;
        }
    }
    if (left_or_right_mouse_button_pressed && !check.is_start_button_pressed && !check.is_ranking_button_pressed
        && !check.is_setting_button_pressed && !check.is_audio_button_pressed && check.is_change_snake_button_pressed == 0 &&
        !check.is_story_mode_pressed && !check.is_survive_mode_pressed && check.is_main_menu_open) {
        if ((mouse_position_is_inside_start_button_in_main_menu))
        {
            // "Start" button pressed
            check.is_start_button_pressed = 1;
            check.is_main_menu_open = 0;
            // start the game
        }
        else if ((mouse_position_is_inside_view_high_score_button_in_main_menu))
        {
            check.is_ranking_button_pressed = 1;
            check.is_main_menu_open = 0;
            // "View High Score" button pressed
            // show the high scores
        }
        else if ((mouse_position_is_inside_setting_button_in_main_menu))
        {
            // "Settings" button pressed
            check.is_setting_button_pressed = 1;
            check.is_main_menu_open = 0;
        }
        else if ((mouse_position_is_inside_exit_button_in_main_menu))
        {
            // "Exit" button pressed
            window.close();
        }
    }


    else if (left_or_right_mouse_button_pressed && mouse_position_is_inside_exit_button_in_ranking_page &&
        check.is_ranking_button_pressed && !check.is_main_menu_open &&
        !check.is_start_button_pressed && !check.is_setting_button_pressed && check.is_audio_button_pressed == 0 &&
        check.is_change_snake_button_pressed == 0 && !check.is_story_mode_pressed && !check.is_survive_mode_pressed) {

        check.is_ranking_button_pressed = 0;

    }


    else if (check.is_setting_button_pressed && left_or_right_mouse_button_pressed && !check.is_audio_button_pressed &&
        !check.is_ranking_button_pressed && !check.is_start_button_pressed && !check.is_change_snake_button_pressed &&
        !check.is_story_mode_pressed && !check.is_survive_mode_pressed) {

        if (mouse_position_is_inside_audio_button_in_setting_page) {
            check.is_audio_button_pressed = 1;
            check.is_setting_button_pressed = 0;
        }
        else if (mouse_position_is_inside_change_color_button_in_setting_page) {
            check.is_change_snake_button_pressed = 1;
            check.is_setting_button_pressed = 0;
        }
        else if (mouse_position_is_inside_exit_button_in_setting_page) {
            check.is_setting_button_pressed = 0;
        }
    }


    else if (left_or_right_mouse_button_pressed && check.is_audio_button_pressed && !check.is_change_snake_button_pressed &&
        !check.is_start_button_pressed && !check.is_ranking_button_pressed && !check.is_setting_button_pressed &&
        !check.is_story_mode_pressed && !check.is_survive_mode_pressed) {
        if (mouse_position_is_inside_ON_Audio_in_audio_setting_page) {
            apple_eating_sound.setVolume(100);
            losing_sound.setVolume(100);
            rotten_apple_eating_sound.setVolume(100);
        }
        else if (mouse_position_is_inside_OFF_Audio_in_setting_page) {
            apple_eating_sound.setVolume(0);
            losing_sound.setVolume(0);
            rotten_apple_eating_sound.setVolume(0);
        }
        else if (mouse_position_is_inside_ON_Music_in_setting_page) {
            music.setVolume(100);
        }
        else if (mouse_position_is_inside_OFF_Music_in_setting_page) {
            music.setVolume(0);
        }
        else if (mouse_position_is_inside_exit_button_in_music_setting_page) {
            check.is_audio_button_pressed = 0;
            check.is_setting_button_pressed = 1;
        }
    }


    else if (left_or_right_mouse_button_pressed && check.is_change_snake_button_pressed && !check.is_audio_button_pressed &&
        !check.is_start_button_pressed && !check.is_ranking_button_pressed && !check.is_setting_button_pressed) {
        if (mouse_position_is_inside_Exit_in_change_color_page)
        {
            check.is_setting_button_pressed = 1;
            check.is_change_snake_button_pressed = 0;
        }
        if (mouse_position_is_inside_first_snake_in_change_color_page)
        {
            check.is_snake_1_being_used = 1;
            check.is_snake_2_being_used = 0;
            check.is_snake_3_being_used = 0;
            check.is_snake_4_being_used = 0;
            check.is_snake_5_being_used = 0;
            check.is_snake_6_being_used = 0;
            check.is_snake_7_being_used = 0;
            check.is_snake_8_being_used = 0;
            check.is_snake_9_being_used = 0;
            check.is_snake_10_being_used = 0;
        }
        else if (mouse_position_is_inside_second_snake_in_change_color_page)
        {
            check.is_snake_1_being_used = 0;
            check.is_snake_2_being_used = 1;
            check.is_snake_3_being_used = 0;
            check.is_snake_4_being_used = 0;
            check.is_snake_5_being_used = 0;
            check.is_snake_6_being_used = 0;
            check.is_snake_7_being_used = 0;
            check.is_snake_8_being_used = 0;
            check.is_snake_9_being_used = 0;
            check.is_snake_10_being_used = 0;
        }
        else if (mouse_position_is_inside_third_snake_in_change_color_page)
        {
            check.is_snake_1_being_used = 0;
            check.is_snake_2_being_used = 0;
            check.is_snake_3_being_used = 1;
            check.is_snake_4_being_used = 0;
            check.is_snake_5_being_used = 0;
            check.is_snake_6_being_used = 0;
            check.is_snake_7_being_used = 0;
            check.is_snake_8_being_used = 0;
            check.is_snake_9_being_used = 0;
            check.is_snake_10_being_used = 0;
        }
        else if (mouse_position_is_inside_forth_snake_in_change_color_page)
        {
            check.is_snake_1_being_used = 0;
            check.is_snake_2_being_used = 0;
            check.is_snake_3_being_used = 0;
            check.is_snake_4_being_used = 1;
            check.is_snake_5_being_used = 0;
            check.is_snake_6_being_used = 0;
            check.is_snake_7_being_used = 0;
            check.is_snake_8_being_used = 0;
            check.is_snake_9_being_used = 0;
            check.is_snake_10_being_used = 0;
        }
        else if (mouse_position_is_inside_fifth_snake_in_change_color_page)
        {
            check.is_snake_1_being_used = 0;
            check.is_snake_2_being_used = 0;
            check.is_snake_3_being_used = 0;
            check.is_snake_4_being_used = 0;
            check.is_snake_5_being_used = 1;
            check.is_snake_6_being_used = 0;
            check.is_snake_7_being_used = 0;
            check.is_snake_8_being_used = 0;
            check.is_snake_9_being_used = 0;
            check.is_snake_10_being_used = 0;
        }
        else if (mouse_position_is_inside_sixth_snake_in_change_color_page)
        {
            check.is_snake_1_being_used = 0;
            check.is_snake_2_being_used = 0;
            check.is_snake_3_being_used = 0;
            check.is_snake_4_being_used = 0;
            check.is_snake_5_being_used = 0;
            check.is_snake_6_being_used = 1;
            check.is_snake_7_being_used = 0;
            check.is_snake_8_being_used = 0;
            check.is_snake_9_being_used = 0;
            check.is_snake_10_being_used = 0;
        }
        else if (mouse_position_is_inside_seventh_snake_in_change_color_page)
        {
            check.is_snake_1_being_used = 0;
            check.is_snake_2_being_used = 0;
            check.is_snake_3_being_used = 0;
            check.is_snake_4_being_used = 0;
            check.is_snake_5_being_used = 0;
            check.is_snake_6_being_used = 0;
            check.is_snake_7_being_used = 1;
            check.is_snake_8_being_used = 0;
            check.is_snake_9_being_used = 0;
            check.is_snake_10_being_used = 0;
        }
        else if (mouse_position_is_inside_eigth_snake_in_change_color_page)
        {
            check.is_snake_1_being_used = 0;
            check.is_snake_2_being_used = 0;
            check.is_snake_3_being_used = 0;
            check.is_snake_4_being_used = 0;
            check.is_snake_5_being_used = 0;
            check.is_snake_6_being_used = 0;
            check.is_snake_7_being_used = 0;
            check.is_snake_8_being_used = 1;
            check.is_snake_9_being_used = 0;
            check.is_snake_10_being_used = 0;
        }
        else if (mouse_position_is_inside_ninth_snake_in_change_color_page)
        {
            check.is_snake_1_being_used = 0;
            check.is_snake_2_being_used = 0;
            check.is_snake_3_being_used = 0;
            check.is_snake_4_being_used = 0;
            check.is_snake_5_being_used = 0;
            check.is_snake_6_being_used = 0;
            check.is_snake_7_being_used = 0;
            check.is_snake_8_being_used = 0;
            check.is_snake_9_being_used = 1;
            check.is_snake_10_being_used = 0;
        }
        else if (mouse_position_is_inside_tenth_snake_in_change_color_page)
        {
            check.is_snake_1_being_used = 0;
            check.is_snake_2_being_used = 0;
            check.is_snake_3_being_used = 0;
            check.is_snake_4_being_used = 0;
            check.is_snake_5_being_used = 0;
            check.is_snake_6_being_used = 0;
            check.is_snake_7_being_used = 0;
            check.is_snake_8_being_used = 0;
            check.is_snake_9_being_used = 0;
            check.is_snake_10_being_used = 1;

        }
        if (mouse_position_is_inside_first_color_option_in_change_color_page)
        {
            check.is_snake_changing_colors = 1;
        }
        else if (mouse_position_is_inside_second_color_option_in_change_color_page)
        {
            check.is_snake_changing_colors = 0;
        }
    }
    else if (left_or_right_mouse_button_pressed && check.is_start_button_pressed && !check.is_change_snake_button_pressed &&
        !check.is_audio_button_pressed && !check.is_ranking_button_pressed && !check.is_setting_button_pressed &&
        !check.is_story_mode_pressed && !check.is_survive_mode_pressed && !check.is_main_menu_open) {
        if (mouse_position_is_inside_story_button) {
            check.is_story_mode_pressed = 1;
            check.is_start_button_pressed = 0;
        }
        else if (mouse_position_is_inside_survival_button) {
            check.is_survive_mode_pressed = 1;
            check.is_start_button_pressed = 0;
        }
        else if (mouse_position_is_inside_exit_button_in_game_modes_page) {
            check.is_start_button_pressed = 0;

        }
    }
    else if (left_or_right_mouse_button_pressed && check.is_story_mode_pressed && !check.is_start_button_pressed && !check.is_change_snake_button_pressed &&
        !check.is_audio_button_pressed && !check.is_ranking_button_pressed && !check.is_setting_button_pressed &&
        !check.is_survive_mode_pressed && !check.is_main_menu_open) {

        if (mouse_position_is_inside_new_game_button_in_story_mode_page) {

        }
        else if (mouse_position_is_inside_continue_button_in_story_mode_page) {

        }
        else if (mouse_position_is_inside_exit_button_in_game_modes_page) {
            check.is_story_mode_pressed = 0;
            check.is_start_button_pressed = 1;
        }
    }

    collision_counter++;
}


void update_game(shape& shapes, int& game_counter, Check& check, int number_of_eaten_apples) {
    //the time it will take the snake to change positions which will make it move faster
    int speedtimer = snake_size_and_speed * 0.25;
    if (check.is_resize_button_pressed) {
        speedtimer *= screen_factor_x;
    }
    //the time it will take the apple to change positions
    int apple_timer = 6 * 50 * screen_factor_x;
    //the time it will take the rotten apple to change positions
    int rotten_apple_timer = apple_timer * 2;

    //the higher the numofapples the lower it take the apple,rotten apple,and snake to change positions
    if (number_of_eaten_apples >= 60) {
        speedtimer *= 0.25;
        apple_timer *= 0.25;
        rotten_apple_timer *= 0.25;
    }
    else if (number_of_eaten_apples >= 40) {
        speedtimer *= 0.5;
        apple_timer *= 0.5;
        rotten_apple_timer *= 0.5;
    }
    else if (number_of_eaten_apples >= 20) {
        speedtimer *= 0.75;
        apple_timer *= 0.75;
        rotten_apple_timer *= 0.75;
    }

    if (game_counter % speedtimer == 0)
        snake_movement(check);
    if (game_counter % apple_timer == 0)
        randapple(shapes, check, number_of_eaten_apples);
    if ((game_counter % rotten_apple_timer == 0))
        randrottenapple(shapes, check, number_of_eaten_apples);
    game_counter++;

}

//use check move
/*to change the direction of the snake when the player presses w / s / a / d or the arrow buttons and it will keep moving
in the same direction as the last button pressed */
void snake_movement(Check& check) {
    bool is_d_or_right_key_pressed = Keyboard::isKeyPressed(Keyboard::D) || Keyboard::isKeyPressed(Keyboard::Right);
    bool is_a_or_left_key_pressed = Keyboard::isKeyPressed(Keyboard::A) || Keyboard::isKeyPressed(Keyboard::Left);
    bool is_s_or_down_key_pressed = Keyboard::isKeyPressed(Keyboard::S) || Keyboard::isKeyPressed(Keyboard::Down);
    bool is_w_or_up_key_pressed = Keyboard::isKeyPressed(Keyboard::W) || Keyboard::isKeyPressed(Keyboard::Up);

    bool snake_isnt_going_left = speed[0][0] != (-1 * snake_size_and_speed);
    bool snake_isnt_going_right = speed[0][0] != snake_size_and_speed;
    bool snake_isnt_going_up = speed[0][1] != -1 * snake_size_and_speed;
    bool snake_isnt_going_down = speed[0][1] != snake_size_and_speed;

    if (is_d_or_right_key_pressed && snake_isnt_going_left) {
        speed[0][0] = snake_size_and_speed; speed[0][1] = 0;
        changexny();
        check.if_the_player_started_playing = 1;
    }
    else if (is_a_or_left_key_pressed && snake_isnt_going_right) {
        speed[0][0] = -1 * snake_size_and_speed; speed[0][1] = 0;
        changexny();
        check.if_the_player_started_playing = 1;
    }
    else if (is_s_or_down_key_pressed && snake_isnt_going_up)
    {
        speed[0][0] = 0; speed[0][1] = snake_size_and_speed;
        changexny();
        check.if_the_player_started_playing = 1;
    }
    else if (is_w_or_up_key_pressed && snake_isnt_going_down)
    {
        speed[0][0] = 0; speed[0][1] = -1 * snake_size_and_speed;
        changexny();
        check.if_the_player_started_playing = 1;
    }
    else {
        if (check.if_the_player_started_playing)
            changexny();

    }
}


//to make sure that all squares moved in their direction and then passed that direction to the next square
void changexny() {
    for (int i = 0; i < MAX_NUMBER_OF_SQUARES; i++) {
        snake[i].move(speed[i][0], speed[i][1]);
    }
    for (int i = MAX_NUMBER_OF_SQUARES - 1; i >= 1; i--) {
        speed[i][0] = speed[i - 1][0];
        speed[i][1] = speed[i - 1][1];
    }
}

//use check apple and collided
//to draw everything in the game
void draw_game(shape& shapes, int& number_of_eaten_apples, Check& check, Font font, shapetextures textures) {

    window.clear(Color(0, 29, 0, 233));
    //Background
    window.draw(game_background);

    //to check if the apple was eaten
    if (check.is_the_apple_eaten == 0) {
        window.draw(shapes.apple_icon);
    }

    if (check.is_the_rotten_apple_eaten == 0 && number_of_eaten_apples > 0) {
        window.draw(shapes.rotten_apple_icon);
    }
    set_texture(number_of_eaten_apples, check, textures);
    for (int square_number = 0; square_number < number_of_eaten_apples + 3; square_number++) {
        set_color(square_number, number_of_eaten_apples, check);
        window.draw(snake[square_number]);

    }
    apple_counter(number_of_eaten_apples, check);
    if (check.is_the_setting_in_game_button_pressed && check.is_the_snake_alive) {
        draw_resume_icon(shapes, check);
        draw_restart_icon(shapes, check);
        draw_exit_icon(shapes, check);

    }
    if (!check.is_the_snake_alive) {
        shapes.game_over.setPosition(500 * screen_factor_x, 50 * screen_factor_y);
        window.draw(shapes.game_over);
        draw_restart_icon(shapes, check);
        draw_exit_icon(shapes, check);
    }
    window.display();

}

void set_texture(int number_of_eaten_apples, Check check, shapetextures& textures) {

    if (check.number_of_snake_being_used==9){
        for (int i = 0; i < number_of_eaten_apples + 3; i++) {
            snake[i].setTexture(NULL);
        }
    }
    else
    {

        for (int i = 0; i < number_of_eaten_apples + 3; i++) {
            if (i == 0)
            {
                if (speed[i][0] == snake_size_and_speed) {

                        snake[i].setTexture(snake_texture[check.number_of_snake_being_used].head_right);

                }
                else if (speed[i][0] == -snake_size_and_speed) {

                        snake[i].setTexture(snake_texture[check.number_of_snake_being_used].head_left);

                }
                else if (speed[i][1] == snake_size_and_speed) {

                        snake[i].setTexture(snake_texture[check.number_of_snake_being_used].head_down);
                }
                else if (speed[i][1] == -snake_size_and_speed) {

                        snake[i].setTexture(snake_texture[check.number_of_snake_being_used].head_up);

                }
            }
            else if (i == number_of_eaten_apples + 2)
            {

                if (speed[i][1] == -snake_size_and_speed) {

                        snake[i].setTexture(snake_texture[check.number_of_snake_being_used].tail_down);

                }
                else if (speed[i][1] == snake_size_and_speed) {

                        snake[i].setTexture(snake_texture[check.number_of_snake_being_used].tail_up);

                }
                else if (speed[i][0] == snake_size_and_speed) {

                    snake[i].setTexture(snake_texture[check.number_of_snake_being_used].tail_left);
                }
                else if (speed[i][0] == -snake_size_and_speed) {

                        snake[i].setTexture(snake_texture[check.number_of_snake_being_used].tail_right);

                }

            }
            else
            {
                if ((speed[i + 1][0] == snake_size_and_speed && speed[i][1] == -snake_size_and_speed) ||
                    (speed[i + 1][1] == snake_size_and_speed && speed[i][0] == -snake_size_and_speed)) {

                        snake[i].setTexture(snake_texture[check.number_of_snake_being_used].body_top_left);

                }
                else if ((speed[i + 1][0] == snake_size_and_speed && speed[i][1] == snake_size_and_speed) ||
                    (speed[i + 1][1] == -snake_size_and_speed && speed[i][0] == -snake_size_and_speed)) {
                  
                        snake[i].setTexture(snake_texture[check.number_of_snake_being_used].body_bottom_left);
                 
                }
                else if ((speed[i + 1][1] == snake_size_and_speed && speed[i][0] == snake_size_and_speed) ||
                    (speed[i + 1][0] == -snake_size_and_speed && speed[i][1] == -snake_size_and_speed)) {
                     snake[i].setTexture(snake_texture[check.number_of_snake_being_used].body_top_right);
                    
                }
                else if ((speed[i + 1][1] == -snake_size_and_speed && speed[i][0] == snake_size_and_speed) ||
                    (speed[i + 1][0] == -snake_size_and_speed && speed[i][1] == snake_size_and_speed)) {
                  
                        snake[i].setTexture(snake_texture[check.number_of_snake_being_used].body_bottom_right);
        
                }

                else if (speed[i][0] == snake_size_and_speed|| speed[i][0] == -snake_size_and_speed) {
                  
                        snake[i].setTexture(snake_texture[check.number_of_snake_being_used].body_horizontal);
      
                }
                else if (speed[i][1] == snake_size_and_speed|| speed[i][1] == -snake_size_and_speed) {
                        snake[i].setTexture(snake_texture[check.number_of_snake_being_used].body_vertical);
                }
                
            }
        }
    }
}

//to change colors of the snake with every key pressed and to change the angle of the rotation of each square based on their direction
void set_color(int square_number, int number_of_eaten_apples, Check check) {
    if (check.is_snake_changing_colors) {
        if (number_of_eaten_apples < 20) {
            if (speed[0][0] == snake_size_and_speed) {
                if (square_number % 2 == 0)
                    snake[square_number].setFillColor(Color::Magenta);
                else
                    snake[square_number].setFillColor(Color::White);
            }
            else if (speed[0][0] == -1 * snake_size_and_speed) {
                if (square_number % 2 == 0)
                    snake[square_number].setFillColor(Color::Green);
                else
                    snake[square_number].setFillColor(Color::Blue);
            }
            else if (speed[0][1] == snake_size_and_speed) {
                if (square_number % 2 == 0)
                    snake[square_number].setFillColor(Color::White);
                else
                    snake[square_number].setFillColor(Color::Red);
            }
            else if (speed[0][1] == -1 * snake_size_and_speed) {
                if (square_number % 2 == 0)
                    snake[square_number].setFillColor(Color::Cyan);
                else
                    snake[square_number].setFillColor(Color::Red);
            }
        }
        else if (number_of_eaten_apples >= 20 && number_of_eaten_apples < 40) {
            if (speed[0][0] == snake_size_and_speed) {
                if (square_number % 2 == 0)
                    snake[square_number].setFillColor(Color::White);
                else
                    snake[square_number].setFillColor(Color::Magenta);
            }
            else if (speed[0][0] == -1 * snake_size_and_speed) {
                if (square_number % 2 == 0)
                    snake[square_number].setFillColor(Color::Black);
                else
                    snake[square_number].setFillColor(Color::Cyan);
            }
            else if (speed[0][1] == snake_size_and_speed) {
                if (square_number % 2 == 0)
                    snake[square_number].setFillColor(Color::Cyan);
                else
                    snake[square_number].setFillColor(Color::Blue);
            }
            else if (speed[0][1] == -1 * snake_size_and_speed) {
                if (square_number % 2 == 0)
                    snake[square_number].setFillColor(Color::Black);
                else
                    snake[square_number].setFillColor(Color::Red);
            }
        }
        else if (number_of_eaten_apples >= 40 && number_of_eaten_apples < 60) {
            if (speed[0][0] == snake_size_and_speed) {
                if (square_number % 2 == 0)
                    snake[square_number].setFillColor(Color::Red);
                else
                    snake[square_number].setFillColor(Color::Magenta);
            }
            else if (speed[0][0] == -1 * snake_size_and_speed) {
                if (square_number % 2 == 0)
                    snake[square_number].setFillColor(Color::Black);
                else
                    snake[square_number].setFillColor(Color::White);
            }
            else if (speed[0][1] == snake_size_and_speed) {
                if (square_number % 2 == 0)
                    snake[square_number].setFillColor(Color::Cyan);
                else
                    snake[square_number].setFillColor(Color::Green);
            }
            else if (speed[0][1] == -1 * snake_size_and_speed) {
                if (square_number % 2 == 0)
                    snake[square_number].setFillColor(Color::Blue);
                else
                    snake[square_number].setFillColor(Color::Red);
            }
        }
        else {
            if (speed[0][0] == snake_size_and_speed) {
                if (square_number % 2 == 0)
                    snake[square_number].setFillColor(Color::Green);
                else
                    snake[square_number].setFillColor(Color::Magenta);
            }
            else if (speed[0][0] == -1 * snake_size_and_speed) {
                if (square_number % 2 == 0)
                    snake[square_number].setFillColor(Color::Magenta);
                else
                    snake[square_number].setFillColor(Color::Cyan);
            }
            else if (speed[0][1] == snake_size_and_speed) {
                if (square_number % 2 == 0)
                    snake[square_number].setFillColor(Color::Cyan);
                else
                    snake[square_number].setFillColor(Color::White);
            }
            else if (speed[0][1] == -1 * snake_size_and_speed) {
                if (square_number % 2 == 0)
                    snake[square_number].setFillColor(Color::Black);
                else
                    snake[square_number].setFillColor(Color::Blue);
            }
        }
    }
    else {
        if (number_of_eaten_apples < 20) {

            snake[square_number].setFillColor(Color::Green);
        }
        else if (number_of_eaten_apples >= 20 && number_of_eaten_apples < 40) {

            snake[square_number].setFillColor(Color::Blue);
        }
        else if (number_of_eaten_apples >= 40 && number_of_eaten_apples < 60) {
            snake[square_number].setFillColor(Color::Red);
        }
        else {
            snake[square_number].setFillColor(Color::Black);
        }

    }
}

//to create score counter
void apple_counter(int number_of_eaten_apples, Check check) {
    // Display score
    text.setFillColor(sf::Color::White);
    text.setCharacterSize(30 * screen_factor_x);
    text.setPosition(70 * screen_factor_x, 20 * screen_factor_y);
    text.setString("Score: " + std::to_string(number_of_eaten_apples));
    window.draw(text);
}

//use check apple
//to change the position of the apple 
void randapple(shape& shapes, Check& check, int number_of_eaten_apples) {
    shapes.apple_icon.setPosition(Vector2f(rand() % ((int)(1005 * screen_factor_x) - (int)snake_size_and_speed) + 145 * screen_factor_x,
        rand() % ((int)(640 * screen_factor_y) - (int)snake_size_and_speed) + 70 * screen_factor_y));

    //to make sure that the apple do not appear on the snake body
    for (int i = 0; i < number_of_eaten_apples + 2; i++) {
        if (snake[i].getGlobalBounds().intersects(shapes.apple_icon.getGlobalBounds())) {
            shapes.apple_icon.setPosition(Vector2f(rand() % ((int)(1005 * screen_factor_x) - (int)snake_size_and_speed) +
                145 * screen_factor_x, rand() % ((int)(640 * screen_factor_y) - (int)snake_size_and_speed) + 70 * screen_factor_y));
            i = 0;
        }
    }
    shapes.apple_icon.setRadius(snake_size_and_speed * 0.5);
    check.is_the_apple_eaten = 0;
}

//to change the position of rotten apple
void randrottenapple(shape& shapes, Check& check, int number_of_eaten_apples) {
    shapes.rotten_apple_icon.setPosition(Vector2f(rand() % ((int)(1005 * screen_factor_x) - (int)snake_size_and_speed) + 145 * screen_factor_x,
        rand() % ((int)(640 * screen_factor_y) - (int)snake_size_and_speed) + 70 * screen_factor_y));
    //to make sure that the rotten apple do not appear on the snake body
    for (int i = 0; i < number_of_eaten_apples + 2; i++) {
        if (snake[i].getGlobalBounds().intersects(shapes.rotten_apple_icon.getGlobalBounds())) {
            shapes.rotten_apple_icon.setPosition(Vector2f(rand() % ((int)(1005 * screen_factor_x) - (int)snake_size_and_speed) + 145 * screen_factor_x,
                rand() % ((int)(640 * screen_factor_y) - (int)snake_size_and_speed) + 70 * screen_factor_y));
            i = 0;
        }
    }

    shapes.rotten_apple_icon.setRadius(snake_size_and_speed);
    check.is_the_rotten_apple_eaten = 0;
}

//o draw the pause button
void draw_resume_icon(shape shapes, Check check) {
    shapes.resume_icon.setFillColor(Color::White);
    shapes.resume_icon.setSize(Vector2f(250, 200));
    shapes.resume_icon.setPosition(550 * screen_factor_x, 200 * screen_factor_y);

    window.draw(shapes.resume_icon);
}

void draw_restart_icon(shape shapes, Check check) {
    if (check.is_the_snake_alive == 0)
        shapes.restart_icon.setPosition(400 * screen_factor_x, 300 * screen_factor_y);
    else
        shapes.restart_icon.setPosition(550 * screen_factor_x, 300 * screen_factor_y);
    shapes.restart_icon.setSize(Vector2f(250, 200));
    shapes.restart_icon.setFillColor(Color::White);
    window.draw(shapes.restart_icon);
}

void draw_exit_icon(shape shapes, Check check) {
    if (check.is_the_snake_alive == 0)
        shapes.exit_icon.setPosition(630 * screen_factor_x, 300 * screen_factor_y);
    else
        shapes.exit_icon.setPosition(550 * screen_factor_x, 400 * screen_factor_y);
    shapes.exit_icon.setSize(Vector2f(250, 200));
    shapes.exit_icon.setFillColor(Color::White);
    window.draw(shapes.exit_icon);
}

void drawMainMenu(Font& font, shape shapes, Check check)
{
    // create the "Start" button
    window.clear(Color(0, 29, 0, 233));

    window.draw(shapes.main_menu_page);
    //Background
    Text startButton;
    startButton.setFont(font);
    startButton.setString("Start");
    startButton.setFillColor(Color::White);


    // create the "View High Score" button
    Text highScoreButton;
    highScoreButton.setFont(font);
    highScoreButton.setString("High Score");
    highScoreButton.setFillColor(Color::White);

    // create the "Exit" button
    Text exitButton;
    exitButton.setFont(font);
    exitButton.setString("Exit");
    exitButton.setFillColor(Color::White);

    startButton.setCharacterSize(32 * screen_factor_x);
    startButton.setPosition(Vector2f((int)(615 * screen_factor_x), (int)(450 * screen_factor_y)));

    highScoreButton.setCharacterSize(29 * screen_factor_x);
    highScoreButton.setPosition(Vector2f((int)(575 * screen_factor_x), (int)(550 * screen_factor_y)));

    exitButton.setCharacterSize(32 * screen_factor_x);
    exitButton.setPosition(Vector2f((int)(625 * screen_factor_x), (int)(650 * screen_factor_y)));

    window.draw(startButton);
    window.draw(highScoreButton);
    window.draw(exitButton);
    window.display();
}

void drawSettingsMenu(Font& font, shape shapes, Check check)
{
    // Background
    window.clear(Color(0, 29, 0, 233));
    window.draw(shapes.setting_page);
    // create the "Audio" button
    Text audioButton;
    audioButton.setFont(font);
    audioButton.setString("Audio");
    audioButton.setFillColor(Color::White);
    audioButton.setCharacterSize(32 * screen_factor_x);
    audioButton.setPosition(Vector2f(window.getSize().x / 2 - 40 * screen_factor_x, window.getSize().y / 2 - 75 * screen_factor_y));

    // create the "fullScreen" button
    Text change_snake_button;
    change_snake_button.setFont(font);
    change_snake_button.setString("Change snake");
    change_snake_button.setFillColor(Color::White);
    change_snake_button.setCharacterSize(32 * screen_factor_x);
    change_snake_button.setPosition(Vector2f(window.getSize().x / 2 - 100 * screen_factor_x, window.getSize().y / 2 + 20 * screen_factor_y));


    // create the "Back" button
    Text backButton;
    backButton.setFont(font);
    backButton.setString("Back");
    backButton.setFillColor(Color::White);
    backButton.setCharacterSize(32 * screen_factor_x);
    backButton.setPosition(Vector2f(window.getSize().x / 2 - 30 * screen_factor_x, window.getSize().y / 2 + 120 * screen_factor_y));


    window.draw(audioButton);
    window.draw(change_snake_button);
    window.draw(backButton);
    window.display();
}

void draw_view_high_score_menu(shape shapes, Text text, int ranking[], Check check)
{
    window.clear();
    window.draw(shapes.ranking_page);
    string number;
    text.setCharacterSize(32 * screen_factor_x);
    text.setStyle(Text::Bold);
    for (int q = 0; q < 3; q++) {
        int u = 1000;

        for (int i = 0; i < 4; i++) {
            if (i > 0)
                u = u / 10;
            number = '0' + ((ranking[q] / u) % 10);
            text.setString(number);
            text.setPosition(Vector2f(725 * screen_factor_x + (20 * i * screen_factor_x), 340 * screen_factor_y + 100 * q * screen_factor_y));
            window.draw(text);
        }
    }

    window.display();

}

void changing_ranking(int number_of_eaten_apples, int ranking[])
{

    int swipe;

    for (int i = 0; i < 3; i++)
    {
        if (ranking[i] < number_of_eaten_apples)
        {
            swipe = ranking[i];
            ranking[i] = number_of_eaten_apples;
            if (i == 0) {
                swap(ranking[1], ranking[2]);
                ranking[1] = swipe;
            }
            else if (i == 1) {
                swap(ranking[2], swipe);
            }
            break;
        }

    }

}

void draw_audio_settings(shape shapes, Check check) {
    window.clear();
    window.draw(shapes.setting_music_page);
    shapes.exit_icon_in_setting_music_page.setPosition(Vector2f(780 * screen_factor_x, 200 * screen_factor_y));
    window.draw(shapes.exit_icon_in_setting_music_page);
    window.display();
}

void draw_change_color(shape shapes, Check& check)
{
    window.clear();
    window.draw(shapes.change_snake_page);

    if (check.is_snake_1_being_used)
    {
        shapes.Tru_ee.setPosition(182 * screen_factor_x, 199 * screen_factor_y);
        check.number_of_snake_being_used = 0;
    }
    else if (check.is_snake_2_being_used)
    {
        shapes.Tru_ee.setPosition(260 * screen_factor_x, 199 * screen_factor_y);
        check.number_of_snake_being_used = 1;

    }
    else if (check.is_snake_3_being_used)
    {
        shapes.Tru_ee.setPosition(337 * screen_factor_x, 199 * screen_factor_y);
        check.number_of_snake_being_used = 2;

    }
    else if (check.is_snake_4_being_used)
    {
        shapes.Tru_ee.setPosition(413 * screen_factor_x, 199 * screen_factor_y);
        check.number_of_snake_being_used = 3;

    }
    else if (check.is_snake_5_being_used)
    {
        shapes.Tru_ee.setPosition(488 * screen_factor_x, 199 * screen_factor_y);
        check.number_of_snake_being_used = 4;

    }
    else if (check.is_snake_6_being_used)
    {
        shapes.Tru_ee.setPosition(562 * screen_factor_x, 199 * screen_factor_y);
        check.number_of_snake_being_used = 5;

    }
    else if (check.is_snake_7_being_used)
    {
        shapes.Tru_ee.setPosition(635 * screen_factor_x, 199 * screen_factor_y);
        check.number_of_snake_being_used = 6;

    }
    else if (check.is_snake_8_being_used)
    {
        shapes.Tru_ee.setPosition(707 * screen_factor_x, 199 * screen_factor_y);
        check.number_of_snake_being_used = 7;

    }
    else if (check.is_snake_9_being_used)
    {
        shapes.Tru_ee.setPosition(778 * screen_factor_x, 199 * screen_factor_y);
        check.number_of_snake_being_used = 8;

    }
    else if (check.is_snake_10_being_used)
    {
        shapes.Tru_ee.setPosition(838 * screen_factor_x, 199 * screen_factor_y);
        check.number_of_snake_being_used = 9;

    }
    window.draw(shapes.Tru_ee);
    if (check.is_snake_changing_colors)
    {
        shapes.Tru_ee.setPosition(464 * screen_factor_x, 341 * screen_factor_y);

    }
    else
    {
        shapes.Tru_ee.setPosition((int)(610 * screen_factor_x), (int)(341 * screen_factor_y));

    }
    window.draw(shapes.Tru_ee);
    window.display();
}
