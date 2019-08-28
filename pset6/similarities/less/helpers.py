from nltk.tokenize import sent_tokenize


def lines(a, b):
    """Return lines in both a and b"""
    # Set two empty lists for the strings and an empty set for the output
    linesA = []
    linesB = []
    lines = set()

    # We split each of the strings in lines, each time we encounter a "\n"
    linesA = a.split("\n")
    linesB = b.split("\n")

    # We compare the lengths of both strings, and use the shortest one as the reference for the iteration
    if len(linesA) > len(linesB):
        length = len(linesB)
    else:
        length = len(linesA)

    # We iterate over every component in the lists, comparing each with all the components of the other string, if a pair match, we add it to the set
    for i in range(length):
        if len(linesB) > len(linesA):
            for j in linesB:
                if j == linesA[i]:
                    lines.add(linesA[i])
        else:
            for j in linesA:
                if j == linesB[i]:
                    lines.add(linesB[i])

    # We return the set as a list
    return list(lines)


def sentences(a, b):
    """Return sentences in both a and b"""
    # Set two empty lists for the strings and an empty set for the output
    sentA = []
    sentB = []
    sent = set()

    # We split each of the strings in sentences, using the sent_tokenize function
    sentA = sent_tokenize(a)
    sentB = sent_tokenize(b)

    # We compare the lengths of both strings, and use the shortest one as the reference for the iteration
    if len(sentA) > len(sentB):
        length = len(sentB)
    else:
        length = len(sentA)

    # We iterate over every component in the lists, comparing each with all the components of the other string, if a pair match, we add it to the set
    for i in range(length):
        if len(sentB) > len(sentA):
            for j in sentB:
                if j == sentA[i]:
                    sent.add(sentA[i])
        else:
            for j in sentA:
                if j == sentB[i]:
                    sent.add(sentB[i])

    # We return the set as a list
    return list(sent)


def substrings(a, b, n):
    """Return substrings of length n in both a and b"""
    # Set two empty lists for the strings and an empty set for the output
    stringA = []
    stringB = []
    string = set()

    # We split each of the strings in fractions of size n, iterating from the beginning until the end
    for i in range(len(a) - n + 1):
        stringA.append(a[i:n + i])

    for j in range(len(b) - n + 1):
        stringB.append(b[j:n + j])

    # We compare the lengths of both strings, and use the shortest one as the reference for the iteration
    if len(stringA) > len(stringB):
        length = len(stringB)
    else:
        length = len(stringA)

    # We iterate over every component in the lists, comparing each with all the components of the other string, if a pair match, we add it to the set
    for i in range(length):
        if len(stringB) > len(stringA):
            for j in stringB:
                if j == stringA[i]:
                    string.add(stringA[i])
        else:
            for j in stringA:
                if j == stringB[i]:
                    string.add(stringB[i])

    # We return the set as a list
    return list(string)
