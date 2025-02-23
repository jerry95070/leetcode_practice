#include <iostream>
#include <vector>
#include <string> 
#include <unordered_map>
using namespace std;

class Character {
    private:
        char m_intrinsicState;
    public:
        Character(char intrinsicState) : m_intrinsicState(intrinsicState) {}

        void draw(int extrinsicState){
            cout << "Drawing character '" << m_intrinsicState << "' at position " << extrinsicState << endl;
        }
};

class CharacterFactory {
    private:
        unordered_map<char, Character*> m_characters;
    public:
        Character* getCharacter(char key){
            if(m_characters.find(key) == m_characters.end()){
                m_characters[key] = new Character(key);
            }
            return m_characters[key];
        }
};

int main(){
    CharacterFactory characterFactory;

    int position = 0;
    characterFactory.getCharacter('A')->draw(position++);
    characterFactory.getCharacter('B')->draw(position++);
    characterFactory.getCharacter('C')->draw(position++);

    return 0;
}