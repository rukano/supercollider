//////////////////////////////////////////////////////////////////////////////
//
// (C) Copyright Ion Gaztanaga 2009.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/move for documentation.
//
//////////////////////////////////////////////////////////////////////////////
#ifndef BOOST_MOVE_TEST_MOVABLE_HPP
#define BOOST_MOVE_TEST_MOVABLE_HPP

//[movable_definition 
//header file "movable.hpp"
#include <boost/move/move.hpp>

//A movable class
class movable
{
   //Non-copyable
   movable(movable &);
   movable & operator=(movable &);

   int value_;

   public:
   BOOST_ENABLE_MOVE_EMULATION(movable)

   movable() : value_(1){}

   //Move constructor and assignment
   movable(BOOST_RV_REF(movable) m)
   {  value_ = m.value_;   m.value_ = 0;  }

   movable & operator=(BOOST_RV_REF(movable) m)
   {  value_ = m.value_;   m.value_ = 0;  return *this;  }

   bool moved() const //Observer
   {  return value_ == 0; }
};

//]

#endif //BOOST_MOVE_TEST_MOVABLE_HPP
