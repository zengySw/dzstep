import React, { useEffect, useState } from 'react';
import './App.css';
import MainLayout from './layout/MainLayout';
import HomePage from './pages/HomePage';
import ProductsPage from './pages/ProductsPage';
import ContactsPage from './pages/ContactsPage';
import NotFoundPage from './pages/NotFoundPage';
import { RouterProvider } from './router/SimpleRouter';
import { productsLoader } from './loaders/productsLoader';

const routes = {
  '/': { page: HomePage },
  '/products': { page: ProductsPage, loader: productsLoader },
  '/contacts': { page: ContactsPage }
};

const getPathFromHash = () => {
  const hashValue = window.location.hash.replace(/^#/, '').trim();
  if (!hashValue) {
    return '/';
  }

  const [pathOnly] = hashValue.split('?');
  return pathOnly.startsWith('/') ? pathOnly : `/${pathOnly}`;
};

const App = () => {
  const [path, setPath] = useState(getPathFromHash);
  const [loaderData, setLoaderData] = useState(null);
  const [isLoading, setIsLoading] = useState(false);
  const [loaderError, setLoaderError] = useState('');

  useEffect(() => {
    const handleHashChange = () => {
      setPath(getPathFromHash());
    };

    window.addEventListener('hashchange', handleHashChange);
    return () => {
      window.removeEventListener('hashchange', handleHashChange);
    };
  }, []);

  useEffect(() => {
    let isCancelled = false;
    const currentRoute = routes[path];

    const runLoader = async () => {
      if (!currentRoute || !currentRoute.loader) {
        setLoaderData(null);
        setLoaderError('');
        setIsLoading(false);
        return;
      }

      setIsLoading(true);
      setLoaderError('');

      try {
        const data = await currentRoute.loader();
        if (!isCancelled) {
          setLoaderData(data);
        }
      } catch (error) {
        if (!isCancelled) {
          setLoaderData(null);
          setLoaderError(error instanceof Error ? error.message : 'Loader failed.');
        }
      } finally {
        if (!isCancelled) {
          setIsLoading(false);
        }
      }
    };

    runLoader();

    return () => {
      isCancelled = true;
    };
  }, [path]);

  const ActivePage = routes[path]?.page ?? NotFoundPage;

  const routerValue = {
    path,
    loaderData,
    isLoading,
    loaderError,
    outlet: <ActivePage />
  };

  return (
    <RouterProvider value={routerValue}>
      <MainLayout />
    </RouterProvider>
  );
};

export default App;
