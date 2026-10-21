#pragma once
#pragma warning(disable : 4996)
#include <ctime>
#include <iostream>
#include <queue>
#include <string>
using namespace std;
class clsQueueLine
{
private:
	string _Prefix = "";
	string TicketNumber = "";
	int _ServeTimeAvg;
	int _WaitingClients = 0;
	int _TotalTickets = 0;
	int _ExpectedServeTime = 0;
	int  _ServedClients = 0;
	string GetSystemDateTimeString()
	{
		//system datetime string
		time_t t = time(0);
		tm* now = localtime(&t);

		short Day, Month, Year, Hour, Minute, Second;

		Year = now->tm_year + 1900;
		Month = now->tm_mon + 1;
		Day = now->tm_mday;
		Hour = now->tm_hour;
		Minute = now->tm_min;
		Second = now->tm_sec;

		return (to_string(Day) + "/" + to_string(Month) + "/"
			+ to_string(Year) + " - "
			+ to_string(Hour) + ":" + to_string(Minute)
			+ ":" + to_string(Second));

	}
public:
	class clsTickets {
	public:
		string TicketNumber;
		string IssueTime;
		int WaitingTime;
		int WaitingClients;
	};
	clsTickets SaveTicket;
	queue <clsTickets> _TicketsQueue;
	clsQueueLine(string Prefix, int ServingMinutes) {
		_ServeTimeAvg = ServingMinutes;
		_Prefix = Prefix;
	}
	void IssueTicket() {
		SaveTicket.WaitingTime = _ExpectedServeTime;
		_ExpectedServeTime += _ServeTimeAvg;
		_TotalTickets++;
		SaveTicket.WaitingClients = _WaitingClients;
		_WaitingClients++;
		TicketNumber = _Prefix + to_string(_TotalTickets);
		SaveTicket.TicketNumber = TicketNumber;
		SaveTicket.IssueTime = GetSystemDateTimeString();
		_TicketsQueue.push(SaveTicket);
	}
	void PrintInfo() {
		cout << "\n\n\t\t\t\t--------------------------------------------------\n";
		cout << "\t\t\t\t\t\t   Queue Info";
		cout << "\n\t\t\t\t--------------------------------------------------\n";
		cout << "\n\t\t\t\t\t\tPrefix : " << _Prefix;
		cout << "\n\t\t\t\t\t\tTotal Tickets : " << _TotalTickets;
		cout << "\n\t\t\t\t\t\tServed Clients : " << _ServedClients;
		cout << "\n\t\t\t\t\t\tWaiting Clients : " << _WaitingClients;
		cout << "\n\n\t\t\t\t--------------------------------------------------\n";
	}
	void PrintTicketsLineRTL() {
		cout << "\n\t\t\t\tTickets : ";
		queue <clsTickets> _TempTicketQueue = _TicketsQueue;
		int size = _TempTicketQueue.size();
		if (!_TempTicketQueue.empty()) {
			for (int i = 0; i < size; i++) {
				cout << _TempTicketQueue.front().TicketNumber;
				_TempTicketQueue.pop();
				if (!_TempTicketQueue.empty())
				{
					cout << " <-- ";
				}
			}
			cout << "\n";
		}
	}
	void PrintTicketsLineLTR() {
		cout << "\n\t\t\t\tTickets : ";

		queue<clsTickets> _TempTicketQueue = _TicketsQueue;

		while (!_TempTicketQueue.empty())
		{
			cout << _TempTicketQueue.front().TicketNumber;

			_TempTicketQueue.pop();

			if (!_TempTicketQueue.empty())
				cout << " --> ";
		}

		cout << "\n";
	}
	void PrintAllTickets() {
		queue <clsTickets> _TempTicketQueue = _TicketsQueue;
		cout << "\n\n\t\t\t\t\t    ----------Tickets----------\n";
		for (int i = 0; i < _TicketsQueue.size(); i++) {
			cout << "\n\t\t\t\t--------------------------------------------------\n";
			cout << "\t\t\t\t\t\t" << _TempTicketQueue.front().TicketNumber << "\n";
			cout << "\t\t\t\t\t\t" << _TempTicketQueue.front().IssueTime << "\n";
			cout << "\t\t\t\t\t\tWaiting Clients : " << _TempTicketQueue.front().WaitingClients << "\n";
			cout << "\t\t\t\t\t\tServe time In\n" << "\t\t\t\t\t\t" << _TempTicketQueue.front().WaitingTime << " Minutes.\n";
			_TempTicketQueue.pop();
		}
	}
	void ServeNextClient() {
		_ServedClients++;
		_WaitingClients--;
		PrintInfo();
		_TicketsQueue.pop();
	}
};