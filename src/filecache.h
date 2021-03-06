/*
Minetest-c55
Copyright (C) 2010 celeron55, Perttu Ahola <celeron55@gmail.com>
Copyright (C) 2012 Jonathan Neuschäfer <j.neuschaefer@gmx.net>

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation; either version 2.1 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License along
with this program; if not, write to the Free Software Foundation, Inc.,
51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
*/

#ifndef FILECACHE_HEADER
#define FILECACHE_HEADER

#include <string>
#include <iostream>

class FileCache
{
public:
	/*
		'dir' is the file cache directory to use.
	*/
	FileCache(std::string dir):
		m_dir(dir)
	{
	}
	
	bool update(const std::string &name, const std::string &data);
	bool update_sha1(const std::string &data);
	bool load(const std::string &name, std::ostream &os);
	bool load_sha1(const std::string &sha1_raw, std::ostream &os);
private:
	std::string m_dir;

	bool loadByPath(const std::string &path, std::ostream &os);
	bool updateByPath(const std::string &path, const std::string &data);
};

#endif
