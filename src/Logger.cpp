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

#include "Logger.h"


Logger::Logger(Level_t level, int maxSize) {
	_maxSize = maxSize;
	_level = level;
	_log = String("");
}

void Logger::debug(String msg) {
	if(_level == levelDebug) {
		log(F("DEBUG"), msg);
	}
}

void Logger::info(String msg) {
	if(_level == levelDebug || _level == levelInfo) {
		log(F("INFO"), msg);
	}
}

void Logger::warn(String msg) {
	if(_level == levelDebug || _level == levelInfo || _level == levelWarn) {
		log(F("WARN"), msg);
	}
}

void Logger::mark() {
	info("--- MARK ---");
}

void Logger::clear() {
	_log = "";
	info("--- CLEAR ---");
}

Logger::Level_t Logger::getLevel() {
	return _level;
}

void Logger::setLevel(Level_t level) {
	_level = level;
}

void Logger::log(String level, String msg) {
	_log.concat(NTP.getTimeStr());
	_log.concat(F(" ["));
	_log.concat(level);
	_log.concat(F("] "));
	_log.concat(msg);
	_log.concat('\n');

	if (_log.length() > _maxSize) {
		_log = _log.substring(_log.length() - _maxSize);
	}
}
