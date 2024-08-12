/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 23:17:18 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/08/12 12:47:38 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Log
{
  public:
	enum	Level
	{
		LevelError,
		LevelWarning,
		LevelInfo
	};
    
	Log()
	{
        X = 0;
        Y = 0;
		std::cout << "Constructor called" << std::endl;
	}
	Log(int x, int y)
	{
        X = x;
        Y = y;
		std::cout << "Constructor with arguments called" << std::endl;
	}
	~Log()
	{
		std::cout << "Destructor called" << std::endl;
	}

  private:
    int X, Y;
	Level	m_Loglevel = LevelInfo;

  public:
	void setLogLevel(Level level)
	{
		m_Loglevel = level;
	}

    void    Print()
    {
        std::cout << X << "," << Y << std::endl;
    }
	void Error(const char *message)
	{
		if (m_Loglevel >= LevelError)
			std::cout << "[ERROR]:" << message << std::endl;
	}

	void Warn(const char *message)
	{
		if (m_Loglevel >= LevelWarning)
			std::cout << "[WARNING]:" << message << std::endl;
	}

	void Info(const char *message)
	{
		if (m_Loglevel >= LevelInfo)
			std::cout << "[INFO]:" << message << std::endl;
	}
};

int	main(void)
{
	Log	log;

	log.setLogLevel(Log::LevelInfo);
	log.Warn("Hello");
	log.Info("Hello");
	log.Error("Hello");
    log.Print();
    Log loglog(4, 444);
    loglog.Print();

	// std::cin.get();
}

// #include <iostream>

// class Log
// {
//     public:
//         enum Level
//         {
//             //  0           1              2
//             LevelError, LevelWarning, LevelInfo
//         }

//     private:
//         Level m_LogLevel = LevelInfo;

//     public:
//         void setLogLevel(Level level)
//         {
//             m_LogLevel = level;
//         }

//         void Error(const char *message)
//         {
//             if (m_LogLevel >= LevelError)
//                 std::cout << "[ERROR]:" << message << std::endl;
//         }

//         void Warn(const char *message)
//         {
//             if (m_LogLevel >= LevelWarning)
//                 std::cout << "[WARNING]:" << message << std::endl;
//         }

//         void Info(const char *message)
//         {
//             if (m_LogLevel >= LevelInfo)
//                 std::cout << "[INFO]:" << message << std::endl;
//         }
// };

// int main(void)
// {
//     Log log;

//     log.setLogLevel(Level::LevelError);
//     log.Warn("Hello");
//     log.Info("Hello");
//     log.Error("Hello");
//     // std::cin.get();
// }