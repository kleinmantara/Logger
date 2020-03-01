/**
 * Logger
 * Copyright (C) 2020 kleinMantara <code@kleinmantara.de>
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 * 
 * code@kleinmantara.de
 * https://github.com/kleinmantara/
 */
#include <Arduino.h>
#include <NtpClientLib.h>



class Logger {

  public:
    typedef enum Level {
      levelWarn,
      levelInfo,
      levelDebug
    } Level_t;

    Logger(Level_t level, int maxSize = 3000);

    void info(String msg);
    void debug(String msg);
    void warn(String msg);
    void mark();
    void clear();
    
    String getMessages();
    
    Level_t getLevel();
    void setLevel(Level_t level);

  private:
    Level_t _level;
    int _maxSize;
    String _log;
    void log(String level, String msg);
};
