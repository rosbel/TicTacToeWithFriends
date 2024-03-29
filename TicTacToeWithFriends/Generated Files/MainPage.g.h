﻿

#pragma once
//------------------------------------------------------------------------------
//     This code was generated by a tool.
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
//------------------------------------------------------------------------------

namespace Windows {
    namespace UI {
        namespace Xaml {
            namespace Controls {
                ref class Grid;
                ref class StackPanel;
                ref class Button;
                ref class TextBlock;
            }
        }
    }
}
namespace Windows {
    namespace UI {
        namespace Xaml {
            ref class VisualStateGroup;
            ref class VisualState;
        }
    }
}

namespace TicTacToeWithFriends
{
    partial ref class MainPage : public ::TicTacToeWithFriends::Common::LayoutAwarePage, 
        public ::Windows::UI::Xaml::Markup::IComponentConnector
    {
    public:
        void InitializeComponent();
        virtual void Connect(int connectionId, ::Platform::Object^ target);
    
    private:
        bool _contentLoaded;
    
        private: ::Windows::UI::Xaml::Controls::Grid^ Title;
        private: ::Windows::UI::Xaml::Controls::StackPanel^ stackPanel;
        private: ::Windows::UI::Xaml::Controls::Grid^ TicTac;
        private: ::Windows::UI::Xaml::Controls::Button^ zero;
        private: ::Windows::UI::Xaml::Controls::Button^ one;
        private: ::Windows::UI::Xaml::Controls::Button^ two;
        private: ::Windows::UI::Xaml::Controls::Button^ three;
        private: ::Windows::UI::Xaml::Controls::Button^ four;
        private: ::Windows::UI::Xaml::Controls::Button^ five;
        private: ::Windows::UI::Xaml::Controls::Button^ six;
        private: ::Windows::UI::Xaml::Controls::Button^ seven;
        private: ::Windows::UI::Xaml::Controls::Button^ eight;
        private: ::Windows::UI::Xaml::Controls::TextBlock^ PlayerY;
        private: ::Windows::UI::Xaml::Controls::TextBlock^ PlayerYScore;
        private: ::Windows::UI::Xaml::Controls::TextBlock^ PlayerX;
        private: ::Windows::UI::Xaml::Controls::TextBlock^ PlayerXScore;
        private: ::Windows::UI::Xaml::Controls::Button^ ResetGame;
        private: ::Windows::UI::Xaml::Controls::TextBlock^ PrintBox;
        private: ::Windows::UI::Xaml::Controls::Button^ ResetStats;
        private: ::Windows::UI::Xaml::Controls::Button^ backButton;
        private: ::Windows::UI::Xaml::Controls::TextBlock^ pageTitle;
        private: ::Windows::UI::Xaml::VisualStateGroup^ ApplicationViewStates;
        private: ::Windows::UI::Xaml::VisualState^ FullScreenLandscape;
        private: ::Windows::UI::Xaml::VisualState^ Filled;
        private: ::Windows::UI::Xaml::VisualState^ FullScreenPortrait;
        private: ::Windows::UI::Xaml::VisualState^ Snapped;
    };
}

