template <typename C, typename F>
auto map(C&& container, F&& func)
{
    using std::begin;
    using std::end;

    using E = std::decay_t<decltype(std::forward<F>(func)(
        *begin(std::forward<C>(container))))>;

    std::vector<E> result;
    auto first = begin(std::forward<C>(container));
    auto last = end(std::forward<C>(container));

    result.reserve(std::distance(first, last));
    for (; first != last; ++first) {
        result.push_back(std::forward<F>(func)(*first));
    }
    return result;
}