func asteroidsDestroyed(mass int, asteroids []int) bool {
    slices.Sort(asteroids)
    for _, v := range asteroids {
        if mass < v {
            return false
        }
        mass += v
    }
    return true
}