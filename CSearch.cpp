#ifndef __PROGTEST__
#include <cctype>
#include <cassert>
#include <cstring>
#include <iostream>
#include <iomanip>
#include <set>
#include <list>
#include <forward_list>
#include <map>
#include <vector>
#include <queue>
#include <string>
#include <deque>
#include <optional>
#include <variant>
#include <any>
#include <algorithm>
#include <functional>
#include <memory>
#include <stdexcept>
using namespace std;
#endif /* __PROGTEST__ */


class DefaultComparator
{
  public:
	DefaultComparator ()
	{ 
	}

	template<class T>
	bool       operator () ( const T & a, const T & b ) const
	{ 
		return a == b; 
	}
};

template <typename _Type, typename _Comparator = DefaultComparator>
class CSearch
{
  public:
	CSearch(_Comparator comp = DefaultComparator())
	: m_Comp(comp)
	{}

	~CSearch() = default;

	CSearch ( const CSearch & src ) = delete;
	CSearch & operator = ( const CSearch & src ) = delete;
	void      Add     ( int           id,
                       const _Type & needle )
	{
		m_Items.insert(pair<int, _Type>(id, needle));
	}

	set<int>  Search  ( const _Type & hayHeap ) const
	{
		set<int> res;
		
		for (auto &i : m_Items)
		{
			if (Searching(i.second, hayHeap))
			{
				res.insert(i.first);
			}
		}
		return res;
	}

  private:
	map<int,_Type> m_Items;
	_Type m_Sequence;
	_Comparator m_Comp;
 
	bool Searching(const _Type & img, const _Type & seq) const
	{
		bool flag = false;
		
		for (auto i = seq.begin(); i != seq.end(); i++)
		{
			auto k = i;
			for (auto j = img.begin(); j != img.end(); j++, k++)
			{
				if (m_Comp(*k, *j))
				{
					flag = true;
				}
				else
				{
					flag = false;
					break;
				}
			}
			if (flag)
				return true;
		}
		return flag;
	}
};
//-------------------------------------------------------------------------------------------------
