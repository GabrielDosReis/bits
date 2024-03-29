// Written by Gabriel Dos Reis.
// Copyright (C), Gabriel Dos Reis.  All rights reserved.
// See the file LICENSE for license.

module;
import std;

// -- This module provides basic operations for manipulating strongly
// -- typed bit bags; a complement to standard header <bit>.
export module GDR.Bits.Utility;

namespace gdr::bits {
    // -- A concept that holds for enumeration type. 
    export template<typename T>
    concept EnumType = std::is_enum_v<T>;

    // -- Same as `rep()`, except the as bag of bits, i.e. unsigned type.
    export template<EnumType T>
    constexpr auto bag(T t)
    {
        using S = std::make_unsigned_t<std::underlying_type_t<T>>;
        return static_cast<S>(std::to_underlying(t));
    }

    // -- Bit mask operations on bitmask enums, sequestered in a dedicated namespace.
    namespace operations {
        export template<EnumType T>
        constexpr T operator&(T x, T y)
        {
            return static_cast<T>(bits::bag(x) & bits::bag(y));
        }

        export template<EnumType T>
        constexpr T operator|(T x, T y)
        {
            return static_cast<T>(bits::bag(x) | bits::bag(y));
        }

        export template<EnumType T>
        constexpr T operator^(T x, T y)
        {
            return static_cast<T>(bits::bag(x) ^ bits::bag(y));
        }

        export template<EnumType T>
        constexpr T operator~(T x)
        {
            return static_cast<T>(~bits::bag(x));
        }
    }
}