#include<iostream>
#include<winsock2.h>
#include<WS2tcpip.h>
#include<system_error>
#include<sys/types.h>
#include<stdio.h>
#include<string.h>
#include<stdint.h>
#include<stdlib.h>

#pragma comment (lib, "Ws2_32.lib")
#pragma comment (lib, "Mswsock.lib")
#pragma comment (lib, "AdvApi32.lib")
#pragma once

int UDPClient(int data_c);
char buffer[100];


namespace ESPConnect
{
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Controller1
	/// </summary>
	public ref class Controller : public System::Windows::Forms::Form
	{
	public:
		Controller(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Controller()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  Forward;
	protected:
	private: System::Windows::Forms::Button^  Backward;
	private: System::Windows::Forms::Button^  Left;
	private: System::Windows::Forms::Button^  Right;
	private: System::Windows::Forms::Button^  Release;








	private: System::Windows::Forms::Label^  MessageRecv;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  LeftPrint;
	private: System::Windows::Forms::Label^  CentralPrint;
	private: System::Windows::Forms::Label^  RightPrint;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->Forward = (gcnew System::Windows::Forms::Button());
			this->Backward = (gcnew System::Windows::Forms::Button());
			this->Left = (gcnew System::Windows::Forms::Button());
			this->Right = (gcnew System::Windows::Forms::Button());
			this->Release = (gcnew System::Windows::Forms::Button());
			this->MessageRecv = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->LeftPrint = (gcnew System::Windows::Forms::Label());
			this->CentralPrint = (gcnew System::Windows::Forms::Label());
			this->RightPrint = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// Forward
			// 
			this->Forward->BackColor = System::Drawing::Color::LightBlue;
			this->Forward->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->Forward->Cursor = System::Windows::Forms::Cursors::Hand;
			this->Forward->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->Forward->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Forward->Location = System::Drawing::Point(134, 72);
			this->Forward->Name = L"Forward";
			this->Forward->Size = System::Drawing::Size(60, 60);
			this->Forward->TabIndex = 0;
			this->Forward->Text = L"/\\";
			this->Forward->UseVisualStyleBackColor = false;
			this->Forward->Click += gcnew System::EventHandler(this, &Controller::Forward_Click);
			// 
			// Backward
			// 
			this->Backward->BackColor = System::Drawing::Color::LightBlue;
			this->Backward->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->Backward->Cursor = System::Windows::Forms::Cursors::Hand;
			this->Backward->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->Backward->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Backward->Location = System::Drawing::Point(134, 138);
			this->Backward->Name = L"Backward";
			this->Backward->Size = System::Drawing::Size(60, 60);
			this->Backward->TabIndex = 1;
			this->Backward->Text = L"\\/";
			this->Backward->UseVisualStyleBackColor = false;
			this->Backward->Click += gcnew System::EventHandler(this, &Controller::Backward_Click);
			// 
			// Left
			// 
			this->Left->BackColor = System::Drawing::Color::LightBlue;
			this->Left->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->Left->Cursor = System::Windows::Forms::Cursors::Hand;
			this->Left->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->Left->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Left->Location = System::Drawing::Point(68, 111);
			this->Left->Name = L"Left";
			this->Left->Size = System::Drawing::Size(60, 60);
			this->Left->TabIndex = 2;
			this->Left->Text = L"<";
			this->Left->UseVisualStyleBackColor = false;
			this->Left->Click += gcnew System::EventHandler(this, &Controller::Left_Click);
			// 
			// Right
			// 
			this->Right->BackColor = System::Drawing::Color::LightBlue;
			this->Right->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->Right->Cursor = System::Windows::Forms::Cursors::Hand;
			this->Right->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->Right->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Right->Location = System::Drawing::Point(200, 111);
			this->Right->Name = L"Right";
			this->Right->Size = System::Drawing::Size(60, 60);
			this->Right->TabIndex = 3;
			this->Right->Text = L">";
			this->Right->UseVisualStyleBackColor = false;
			this->Right->Click += gcnew System::EventHandler(this, &Controller::Right_Click);
			// 
			// Release
			// 
			this->Release->BackColor = System::Drawing::Color::LightBlue;
			this->Release->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->Release->Cursor = System::Windows::Forms::Cursors::Hand;
			this->Release->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->Release->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Release->Location = System::Drawing::Point(99, 204);
			this->Release->Name = L"Release";
			this->Release->Size = System::Drawing::Size(130, 60);
			this->Release->TabIndex = 4;
			this->Release->Text = L"STOP";
			this->Release->UseVisualStyleBackColor = false;
			// 
			// MessageRecv
			// 
			this->MessageRecv->AutoSize = true;
			this->MessageRecv->BackColor = System::Drawing::Color::Lavender;
			this->MessageRecv->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->MessageRecv->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.749999F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->MessageRecv->Location = System::Drawing::Point(82, 356);
			this->MessageRecv->Name = L"MessageRecv";
			this->MessageRecv->Size = System::Drawing::Size(0, 16);
			this->MessageRecv->TabIndex = 13;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->BackColor = System::Drawing::Color::Lavender;
			this->label5->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.749999F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(12, 320);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(0, 16);
			this->label5->TabIndex = 9;
			this->label5->Click += gcnew System::EventHandler(this, &Controller::label5_Click);
			// 
			// LeftPrint
			// 
			this->LeftPrint->AutoSize = true;
			this->LeftPrint->Location = System::Drawing::Point(61, 41);
			this->LeftPrint->Name = L"LeftPrint";
			this->LeftPrint->Size = System::Drawing::Size(0, 13);
			this->LeftPrint->TabIndex = 14;
			// 
			// CentralPrint
			// 
			this->CentralPrint->AutoSize = true;
			this->CentralPrint->Location = System::Drawing::Point(159, 25);
			this->CentralPrint->Name = L"CentralPrint";
			this->CentralPrint->Size = System::Drawing::Size(0, 13);
			this->CentralPrint->TabIndex = 15;
			// 
			// RightPrint
			// 
			this->RightPrint->AutoSize = true;
			this->RightPrint->Location = System::Drawing::Point(283, 41);
			this->RightPrint->Name = L"RightPrint";
			this->RightPrint->Size = System::Drawing::Size(0, 13);
			this->RightPrint->TabIndex = 16;
			// 
			// Controller
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Ivory;
			this->ClientSize = System::Drawing::Size(336, 277);
			this->Controls->Add(this->RightPrint);
			this->Controls->Add(this->CentralPrint);
			this->Controls->Add(this->LeftPrint);
			this->Controls->Add(this->MessageRecv);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->Release);
			this->Controls->Add(this->Right);
			this->Controls->Add(this->Left);
			this->Controls->Add(this->Backward);
			this->Controls->Add(this->Forward);
			this->Name = L"Controller";
			this->Text = L"Controller";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion 
	private: System::Void Forward_Click(System::Object^  sender, System::EventArgs^  e)
	{
		UDPClient(1);
	}
	private: System::Void Backward_Click(System::Object^  sender, System::EventArgs^  e)
	{
		UDPClient(4);
	}
	private: System::Void Left_Click(System::Object^  sender, System::EventArgs^  e)
	{
		UDPClient(2);
	}
	private: System::Void Right_Click(System::Object^  sender, System::EventArgs^  e)
	{
		UDPClient(3);
	}
	private: System::Void label2_Click(System::Object^  sender, System::EventArgs^  e)
	{

	}
	
	private: System::Void label3_Click(System::Object^  sender, System::EventArgs^  e)
	{
		
	}
	private: System::Void label5_Click(System::Object^  sender, System::EventArgs^  e)
	{

	}
	private: System::Void label8_Click(System::Object^  sender, System::EventArgs^  e)
	{
	}
	private: System::Void Release_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		UDPClient(5);
	}
};
};

class WSASession
{
public:
	WSASession()
	{
		int ret = WSAStartup(MAKEWORD(2, 2), &data);
		if (ret != 0)
			throw std::system_error(WSAGetLastError(), std::system_category(), "WSAStartup Failed");
	}
	~WSASession()
	{
		WSACleanup();
	}
private:
	WSAData data;
};
class UDPSocket
{
public:
	UDPSocket()
	{
		sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
		if (sock == INVALID_SOCKET)
			throw std::system_error(WSAGetLastError(), std::system_category(), "Error opening socket");
	}
	~UDPSocket()
	{
		closesocket(sock);
	}

	void SendTo(const std::string& address, unsigned short port, const char* buffer, int len, int flags = 0)
	{
		sockaddr_in add;
		add.sin_family = AF_INET;
		add.sin_addr.s_addr = inet_addr(address.c_str());
		add.sin_port = htons(port);
		int ret = sendto(sock, buffer, len, flags, reinterpret_cast<SOCKADDR *>(&add), sizeof(add));
		if (ret < 0)
			throw std::system_error(WSAGetLastError(), std::system_category(), "sendto failed");
	}
	void SendTo(sockaddr_in& address, const char* buffer, int len, int flags = 0)
	{
		int ret = sendto(sock, buffer, len, flags, reinterpret_cast<SOCKADDR *>(&address), sizeof(address));
		if (ret < 0)
			throw std::system_error(WSAGetLastError(), std::system_category(), "sendto failed");
	}
	sockaddr_in RecvFrom(char* buffer, int len, int flags = 0)
	{
		sockaddr_in from;
		int size = sizeof(from);
		int ret = recvfrom(sock, buffer, len, flags, reinterpret_cast<SOCKADDR *>(&from), &size);
		if (ret < 0)
			throw std::system_error(WSAGetLastError(), std::system_category(), "recvfrom failed");
		buffer[ret] = 0;
		return from;
	}

	void Bind(unsigned short port)
	{
		sockaddr_in add;
		add.sin_family = AF_INET;
		add.sin_addr.s_addr = htonl(INADDR_ANY);
		add.sin_port = htons(port);

		int ret = bind(sock, reinterpret_cast<SOCKADDR *>(&add), sizeof(add));
		if (ret < 0)
			throw std::system_error(WSAGetLastError(), std::system_category(), "Bind failed");
	};

private:
	SOCKET sock;
};


int UDPClient(int data_c)
{
	WSASession Session;
	UDPSocket Socket;
	std::string data;
	std::string IP = "192.168.137.157";
	if (data_c == 1)
	{
		data = 'w';
		Socket.SendTo(IP, 4210, data.c_str(), data.size());
	}
	if (data_c == 2)
	{
		data = 'a';
		Socket.SendTo(IP, 4210, data.c_str(), data.size());
	}
	if (data_c == 3)
	{
		data = 'd';
		Socket.SendTo(IP, 4210, data.c_str(), data.size());
	}
	if (data_c == 4)
	{
		data = 's';
		Socket.SendTo(IP, 4210, data.c_str(), data.size());
	}
	if (data_c == 5)
	{
		data = 'v';
		Socket.SendTo(IP, 4210, data.c_str(), data.size());
	}

	return 0;
}
