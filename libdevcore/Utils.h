/*
	This file is part of solidity.

	solidity is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	solidity is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with solidity.  If not, see <http://www.gnu.org/licenses/>.
*/

namespace dev
{

/// Increments @p incrementable and ensures it is getting decremented upon destruction of the returned value.
///
/// Use this to ensure scoped increments/decrements in your code.
template <typename Incrementable>
auto inline scopedIncrement(Incrementable& incrementable)
{
	struct ScopedIncrement {
		Incrementable& value;
		~ScopedIncrement() { --value; }
	};
	return ScopedIncrement{ ++incrementable };
}

template <typename Callable>
auto inline atScopeExit(Callable callable)
{
	struct ExitCode {
		T leave;
		~ExitCode() { leave(); }
	};
	return ExitCode{ std::move(leave) };
}

} // namespace dev
