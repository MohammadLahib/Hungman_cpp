#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <random>
#include <ctime>
using namespace std;

void base(){
    cout<<"  +---+ \n";
    cout<<"  |   | \n";
    cout<<"      | \n";
    cout<<"      | \n";
    cout<<"      | \n";
    cout<<"      | \n";
    cout<<" ========= \n";
}

void head(){
    cout<<"  +---+ \n";
    cout<<"  |   | \n";
    cout<<"  O   | \n";
    cout<<"      | \n";
    cout<<"      | \n";
    cout<<"      | \n";
    cout<<" ========= \n";
}

void torso (){
    cout<<"  +---+ \n";
    cout<<"  |   | \n";
    cout<<"  O   | \n";
    cout<<"  |   | \n";
    cout<<"      | \n";
    cout<<"      | \n";
    cout<<" ========= \n";
}

void leftarm(){
     cout<<"  +---+ \n";
    cout<<"  |   | \n";
    cout<<"  O   | \n";
    cout<<" /|   | \n";
    cout<<"      | \n";
    cout<<"      | \n";
    cout<<" ========= \n";
}

void rightarm(){
    cout<<"  +---+ \n";
    cout<<"  |   | \n";
    cout<<"  O   | \n";
    cout<<" /|\\  | \n";
    cout<<"      | \n";
    cout<<"      | \n";
    cout<<" ========= \n";
}
  
void leftleg(){
    cout<<"  +---+ \n";
    cout<<"  |   | \n";
    cout<<"  O   | \n";
    cout<<" /|\\  | \n";
    cout<<" /    | \n";
    cout<<"      | \n";
    cout<<" ========= \n";
}
  
void rightleg(){
    cout<<"  +---+ \n";
    cout<<"  |   | \n";
    cout<<"  O   | \n";
    cout<<" /|\\  | \n";
    cout<<" / \\  | \n";
    cout<<"      | \n";
    cout<<" ========= \n";
}

class Hung{
  private:
    int lenword= 4;
    
  public:
    void display_status(vector<char> incorrect, string answer)
    {
      cout<<"\nIncorrect letters: \n";

      for(int i = 0; i<incorrect.size(); i++)
      {
        cout<<incorrect[i]<<" ";
      }

      cout<<"\ncorrect letters:\n";

      for(int i = 0; i<answer.length(); i++)
      {
        cout<<answer[i]<<" ";
      }
    }


    vector<string> words;

    string Random()
    {
        std::string word;

        ifstream f{ "words.txt" };
        if (f.is_open()) {
            while (getline(f, word)) {
                if (word.length() >= lenword) {
                    words.push_back(word);
                }
            }
            srand((int)time(0));
          int i = rand() % words.size();
          return words.at(i);
        }
        return word;

    }


};

int main()
{

void (*painter[7])() = { &head, &torso, &leftarm, &rightarm , &leftleg, &rightleg };
  Hung h;
  string word =  h.Random();
  string answer = "";
  for (int i = 0 ; i < word.length();i++){
      answer += "-";
  }
  int misses = 0;
  vector<char> incorrect;
  bool guess = false;

  char letter;


  while(answer!=word && misses < 6)
  {
    h.display_status(incorrect, answer);

    // cout << word;

    cout<<"\nEnter your guess: ";
    cin>>letter;

    for(int i = 0; i<word.length(); i++)
    {
      if(letter==word[i])
      {
        answer[i] = letter;
        guess = true;
      }
    }
    if(guess)
    {
      cout<<"\nCorrect!\n";
      cout <<"\n<<<<<<<>>>>>>>>>>>\n";
    }
    else
    {
    
      incorrect.push_back(letter);
      painter[misses++]();
    }
    guess = false;
  }

  if(answer==word)
  {
    cout<<"You win\n";
    cout<<"Congratulations!\n";
    cout << "\nThe word is " <<word;
  }
  else
  {
    cout<<"The man is hanged!\n";
    cout << "\nThe word was " << word << endl;
  }

  return 0;
}
