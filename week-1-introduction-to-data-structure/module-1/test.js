useEffect(() => {
  const unSubscribe = onAuthStateChanged(auth, (currentUser) => {
    console.log(currentUser);
    if (!currentUser?.emailVerified) {
      emailVerification(currentUser);
      userSignOut();
      return;
    } else {
      setUser(currentUser);
      console.log(currentUser);
    }
    setLoading(false);
  });

  return () => {
    unSubscribe();
  };
}, []);
