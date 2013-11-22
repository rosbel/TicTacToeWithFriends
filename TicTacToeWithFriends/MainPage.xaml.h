//
// MainPage.xaml.h
// Declaration of the MainPage class
//

#pragma once

#include "Common\LayoutAwarePage.h" // Required by generated header
#include "MainPage.g.h"

namespace TicTacToeWithFriends
{
	/// <summary>
	/// A basic page that provides characteristics common to most applications.
	/// </summary>
	public ref class MainPage sealed
	{
	public:
		MainPage();

	private:
		bool playerTurn;
		bool gamecomplete;
		std::vector<std::vector<bool> > player; //player[i][j] i will be player#, j will be button pressed;
		std::vector<bool> buttonPressed;

		//Win possibilities		
		std::vector<std::vector<int> > possibilities;

		//SolidColorBrush StartColor;

	

	protected:
		virtual void LoadState(Platform::Object^ navigationParameter,
			Windows::Foundation::Collections::IMap<Platform::String^, Platform::Object^>^ pageState) override;
		virtual void SaveState(Windows::Foundation::Collections::IMap<Platform::String^, Platform::Object^>^ pageState) override;
	private:
		Windows::UI::Xaml::Controls::Button^ getButton(int index);
		void Button_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		bool checkForEnd(int& Winner);
		bool checkPossibility(std::vector<int> possible, std::vector<int> jugador, std::vector<Windows::UI::Xaml::Controls::Button^>& buttons);
		void updateButton(int place, bool &turn, Windows::UI::Xaml::Controls::Button^ button);
		void ResetGame_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void ResetStats_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
	};
}
