int lengthOfLastWord(std::string s)
{
    short lastChar = s.find_last_not_of(" ");
    return (lastChar - s.rfind(" ",lastChar));
}
