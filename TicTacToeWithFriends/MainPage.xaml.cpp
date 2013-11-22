//
// MainPage.xaml.cpp
// Implementation of the MainPage class
//

#include "pch.h"
#include "MainPage.xaml.h"
#include <sstream>

using namespace TicTacToeWithFriends;

using namespace Platform;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Controls::Primitives;
using namespace Windows::UI::Xaml::Data;
using namespace Windows::UI::Xaml::Input;
using namespace Windows::UI::Xaml::Media;
using namespace Windows::UI::Xaml::Navigation;

// The Basic Page item template is documented at http://go.microsoft.com/fwlink/?LinkId=234237

MainPage::MainPage()
{
	//StartColor = safe_cast<SolidColorBrush^>(getButton(0)->Background);
	//Fill in the winning possitions
	std::vector<int> row1;		//0,1,2
	std::vector<int> row2;		//3,4,5
	std::vector<int> row3;		//6,7,8
	std::vector<int> column1;	 //0,3,6
	std::vector<int> column2;	//1,4,7
	std::vector<int> column3;	 //2,5,8
	std::vector<int> diag1;		//{0,4,8};
	std::vector<int> diag2;		//{2,4,6};

	for(int i = 0; i < 3; i++){ row1.push_back(i); }			//0,1,2
	for(int i = 0; i < 3; i++){ row2.push_back(i+3); }			//3,4,5										
	for(int i = 0; i < 3; i++){ row3.push_back(i+6); }			//6,7,8
	for(int i = 0; i < 3; i++){ column1.push_back(i*3); }		//0,3,6
	for(int i = 0; i < 3; i++){ column2.push_back((i*3)+1); }	//1,4,7
	for(int i = 0; i < 3; i++){ column3.push_back((i*3)+2); }	//2,5,8
	for(int i = 0; i < 3; i++){ diag1.push_back(i*4); }			//0,4,8
	for(int i = 0; i < 3; i++){ diag2.push_back((i*2)+2);}		//2,4,6
	possibilities.push_back(row1);
	possibilities.push_back(row2);
	possibilities.push_back(row3);
	possibilities.push_back(column1);
	possibilities.push_back(column2);
	possibilities.push_back(column3);
	possibilities.push_back(diag1);
	possibilities.push_back(diag2);

	
	std::vector<bool> player1;
	std::vector<bool> player2;
	player.push_back(player1); //two players
	player.push_back(player2);
	for(int i = 0; i < 2; i++)
	{
		for(int j = 0; j < 9; j++)
		{
			player[i].push_back(false);
		}
	}
	for(int i = 0; i < 9; i++)
	{
		buttonPressed.push_back(false); //initialize all buttons to false
	}
	playerTurn = 0; //set player to two because as soon as button is pressed, player will go back to player 1


	InitializeComponent();
	gamecomplete = false;
}

/// <summary>
/// Populates the page with content passed during navigation.  Any saved state is also
/// provided when recreating a page from a prior session.
/// </summary>
/// <param name="navigationParameter">The parameter value passed to
/// <see cref="Frame::Navigate(Type, Object)"/> when this page was initially requested.
/// </param>
/// <param name="pageState">A map of state preserved by this page during an earlier
/// session.  This will be null the first time a page is visited.</param>
void MainPage::LoadState(Object^ navigationParameter, IMap<String^, Object^>^ pageState)
{
	(void) navigationParameter;	// Unused parameter
	(void) pageState;	// Unused parameter
}

/// <summary>
/// Preserves state associated with this page in case the application is suspended or the
/// page is discarded from the navigation cache.  Values must conform to the serialization
/// requirements of <see cref="SuspensionManager::SessionState"/>.
/// </summary>
/// <param name="pageState">An empty map to be populated with serializable state.</param>
void MainPage::SaveState(IMap<String^, Object^>^ pageState)
{
	(void) pageState;	// Unused parameter
}


bool MainPage::checkPossibility(std::vector<int> possible, std::vector<int> jugador, std::vector<Button^>& buttons)
{
	int count = 0;
	std::vector<Button^> winbuttons;
	for(int i = 0; i < jugador.size(); i++)
	{
		for(int j = 0; j < 3; j++)
		{
			if(jugador[i] == possible[j])
			{
				winbuttons.push_back(getButton(possible[j]));
				count++;
			}
		}
		if (count == 3)
		{
			buttons = winbuttons;
			return true;
		}
	}
	return false;	
}


Button^ MainPage::getButton(int index)
{
	if (index == 0)
		return zero;
	else if (index == 1)
		return one;
	else if (index == 2)
		return two;
	else if (index == 3)
		return three;
	else if (index == 4)
		return four;
	else if (index == 5)
		return five;
	else if (index == 6)
		return six;
	else if (index == 7)
		return seven;
	else if (index == 8)
		return eight;
	else
		return nullptr;

}

bool MainPage::checkForEnd(int& Winner)
{
	bool finished = true;
	for(int i = 0; i < buttonPressed.size(); i++)
	{
		if(!buttonPressed[i])
		{
			finished = false;
			break;
		}
	}

	std::vector<int> player1;
	std::vector<int> player2;

	for(int j = 0; j < 9; j++)
	{
		if(player[0][j] == true)  player1.push_back(j); //j is current position in table 0..8
		if(player[1][j] == true) player2.push_back(j);
	}
	
	for(int i = 0; i < possibilities.size(); i++)
	{
		std::vector<Button^> winningbuttons;
		if(checkPossibility(possibilities[i],player1,winningbuttons))
		{
			Winner = 1;
			for(int i = 0; i < winningbuttons.size(); i++)
			{
				winningbuttons[i]->Background = ref new SolidColorBrush(Windows::UI::Colors::Green);
			}
			finished = true;
		}
		if(checkPossibility(possibilities[i],player2,winningbuttons))
		{
			Winner = 2;
			auto color = ref new SolidColorBrush(Windows::UI::Colors::Green);
			for(int i = 0; i < winningbuttons.size(); i++)
			{
				winningbuttons[i]->Background = color;
			}
			finished = true;
		}
	}

	if(finished)
	{
		for(int i = 0; i < buttonPressed.size(); i++)
		{
			buttonPressed[i] = true;
		}
		return true;
	}
	else
	{
		return false;
	}
}

void TicTacToeWithFriends::MainPage::Button_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{	
	
	Button^ button = safe_cast<Button^>(sender);
	std::wstring name = button->Name->ToString()->Data();
	// change player turn
	
	if(name == L"zero")
	{
		int i = 0;
		updateButton(i,playerTurn,button);
	}
	else if(name == L"one")
	{
		int i = 1;
		updateButton(i,playerTurn,button);
	}
	else if(name == L"two")
	{
		int i = 2;
		updateButton(i,playerTurn,button);
	}
	else if(name == L"three")
	{
		int i = 3;
		updateButton(i,playerTurn,button);
	}
	else if(name == L"four")
	{
		int i = 4;
		updateButton(i,playerTurn,button);
	}
	else if(name == L"five")
	{
		int i = 5;
		updateButton(i,playerTurn,button);
	}
	else if(name == L"six")
	{
		int i = 6;
		updateButton(i,playerTurn,button);
	}
	else if(name == L"seven")
	{
		int i = 7;
		updateButton(i,playerTurn,button);
	}
	else if(name == L"eight")
	{
		int i = 8;
		updateButton(i,playerTurn,button);
	}
	int winner = 0;

	if(checkForEnd(winner) && !gamecomplete)
	{
		gamecomplete = true;
		if(winner == 1)
		{
			PrintBox->Text = L"X Wins!";
			//add one to player 1's win later
			std::wstringstream data;
			data << PlayerXScore->Text->Data();
			int score;
			data >> score;
			score++;
			PlayerXScore->Text = score.ToString();
		}
		else if(winner == 2)
		{
			PrintBox->Text = L"O Wins!";
			std::wstringstream data;
			data << PlayerYScore->Text->Data();
			int score;
			data >> score;
			score++;
			PlayerYScore->Text = score.ToString();
		}
		else
		{
			PrintBox->Text = L"DRAW!";
			auto color = ref new SolidColorBrush(Windows::UI::Colors::Red);
			for(int i = 0; i < 9; i++)
			{
				getButton(i)->Background = color;
			}
		}
	}
}

void MainPage::updateButton(int place, bool &turn, Button^ button)
{
	if(!buttonPressed[place])
		{
			player[turn][place] = true;
			buttonPressed[place] = true;
			if(turn)
			{
				button->Content = L"O";
				PrintBox->Text = L"X's Turn";
			}
			else
			{
				button->Content = L"X";
				PrintBox->Text = L"O's Turn";
			}
			turn = !turn;
		}
}

void TicTacToeWithFriends::MainPage::ResetGame_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	zero->Content= L"";
	one->Content = L"";
	two->Content = L"";
	three->Content = L"";
	four->Content = L"";
	five->Content = L"";
	six->Content = L"";
	seven->Content = L"";
	eight->Content = L"";

	for(int i = 0; i < buttonPressed.size(); i++)
	{
		buttonPressed[i] = false;
	}
	for(int i = 0; i < player.size(); i++)
	{
		for(int j = 0; j < player[i].size(); j++)
		{
			player[i][j] = false;
		}
	}
	auto StartColor = ref new SolidColorBrush(Windows::UI::Colors::Transparent); //fix
	for(int i = 0; i < 9; i++)
	{
		getButton(i)->Background = StartColor; // fix
	}
	playerTurn = 0;
	PrintBox->Text = L"X's Turn";
	gamecomplete = false;
}


void TicTacToeWithFriends::MainPage::ResetStats_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	zero->Content= L"";
	one->Content = L"";
	two->Content = L"";
	three->Content = L"";
	four->Content = L"";
	five->Content = L"";
	six->Content = L"";
	seven->Content = L"";
	eight->Content = L"";

	for(int i = 0; i < buttonPressed.size(); i++)
	{
		buttonPressed[i] = false;
	}
	for(int i = 0; i < player.size(); i++)
	{
		for(int j = 0; j < player[i].size(); j++)
		{
			player[i][j] = false;
		}
	}
	auto StartColor = ref new SolidColorBrush(Windows::UI::Colors::Transparent); //fix
	for(int i = 0; i < 9; i++)
	{
		getButton(i)->Background = StartColor;
	}
	playerTurn = 0;
	PrintBox->Text = L"X's Turn";
	PlayerXScore->Text = L"0";
	PlayerYScore->Text = L"0";
	gamecomplete = false;
}
